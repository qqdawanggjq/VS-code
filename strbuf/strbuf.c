#include"strbuf.h"
void strbuf_init(struct strbuf *sb, size_t alloc)
{
    if(alloc==0)alloc=1;
    sb->len=0;
    sb->alloc=alloc;
    sb->buf=(char*)malloc(alloc*sizeof(char));
    if(sb->buf==NULL)
    {
        exit(1);
    }
    sb->buf[0]='\0';
}
void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc)
{
    if(alloc<=len)alloc=len+1;
    if(sb->alloc<alloc)
    {
        char* p=(char*)realloc(sb->buf,alloc);
        if(p==NULL)
        {
            exit(1);
        }
        sb->buf=p;
        sb->alloc=alloc;
    }
    memcpy(sb->buf,str,len);
    sb->buf[len]='\0';
    sb->len=len;
}
void strbuf_release(struct strbuf *sb)
{
    free(sb->buf);
    sb->buf=NULL;
    sb->alloc=0;
    sb->len=0;
}
void strbuf_swap(struct strbuf *a, struct strbuf *b)
{
    struct strbuf p=*a;
    *a=*b;
    *b=p;
}
char *strbuf_detach(struct strbuf *sb, size_t *sz)
{
    char* p=sb->buf;
    *sz=sb->alloc;
    sb->buf=NULL;
    sb->len=0;
    sb->alloc=0;
    return p;
}
int strbuf_cmp(const struct strbuf *first, const struct strbuf *second)
{
    int length=first->len;
    if(second->len<first->len)length=second->len;
    int n=memcmp(first->buf,second->buf,length);
    if(n!=0)return n;
    if(first->len>second->len)return 1;
    if(second->len>first->len)return -1;
    return 0;
}
void strbuf_reset(struct strbuf *sb)
{
    sb->len=0;
    if(sb->buf!=NULL)
    {
        sb->buf[0]='\0';
    }
}
void strbuf_grow(struct strbuf *sb, size_t extra)
{
    size_t need=(size_t)sb->len+extra+1;
    if(need<=sb->alloc)return;
    size_t new_alloc=sb->alloc;
    if(new_alloc==0)
    {
        new_alloc=1;
    }
    while(new_alloc<need)
    {
        new_alloc*=2;
    }
    char* p=(char*)realloc(sb->buf,new_alloc);
    if(p==NULL)exit(1);
    sb->alloc=new_alloc;
    sb->buf=p;
    if(sb->len==0)
    {
        sb->buf[0]='\0';
    }
}
void strbuf_add(struct strbuf *sb,const void *data,size_t len)
{
    strbuf_grow(sb,len);
    memcpy(sb->buf+sb->len,data,len);
    sb->len+=len;
    sb->buf[sb->len]='\0';
}
void strbuf_addch(struct strbuf *sb, int c)
{
    strbuf_grow(sb,1);
    sb->buf[sb->len]=c;
    sb->len++;
    sb->buf[sb->len]='\0';
}
void strbuf_addstr(struct strbuf *sb, const char *s)
{
    strbuf_add(sb,s,strlen(s));
}
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2)
{
    strbuf_add(sb,sb2->buf,sb2->len);
}
void strbuf_setlen(struct strbuf *sb, size_t len)
{
    if(len>=sb->alloc)
    {
        strbuf_grow(sb,len-sb->len);
    }
    sb->len=len;
    sb->buf[sb->len]='\0';
}
size_t strbuf_avail(const struct strbuf *sb)
{
    if(sb->alloc<=sb->len)return 0;
    return sb->alloc-sb->len-1;
}
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len)
{
    if(pos>sb->len||len==0)return;
    strbuf_grow(sb,len);
    memmove(sb->buf+pos+len,sb->buf+pos,sb->len-pos+1);
    memcpy(sb->buf+pos,data,len);
    sb->len+=len;
}
void strbuf_ltrim(struct strbuf *sb)
{
    int n=0;
    while(n<sb->len&&(sb->buf[n]==' '||sb->buf[n]=='\t'))n++;
    if(n==0)return;
    memmove(sb->buf,sb->buf+n,sb->len-n+1);
    sb->len-=n;
}
void strbuf_rtrim(struct strbuf *sb)
{
    int num=0,n=sb->len-1;
    while(n>=0&&(sb->buf[n]==' '||sb->buf[n]=='\t'))
    {
        n--;
        num++;
    }
    if(num==0)return;
    sb->len-=num;
    sb->buf[sb->len]='\0';
}
void strbuf_remove(struct strbuf *sb, size_t pos, size_t len)
{
    if(pos>=sb->len||len==0)return;
    if(len>sb->len-pos)
    {
        len=sb->len-pos;
    }
    memmove(sb->buf+pos,sb->buf+pos+len,sb->len-pos-len+1);
    sb->len-=len;
}
ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint)
{
    size_t old_len=sb->len;
    if(hint==0)hint=8192;
    while(1)
    {
        if(strbuf_avail(sb)==0)
        {
            strbuf_grow(sb,hint);
        }
        ssize_t n=read(fd,sb->buf+sb->len,strbuf_avail(sb));
        if(n<0)return -1;
        if(n==0) break;
        sb->len+=n;
        sb->buf[sb->len]='\0';
    }
    return sb->len-old_len;
}
int strbuf_getline(struct strbuf *sb, FILE *fp)
{
    strbuf_reset(sb);
    int ch;
    while((ch=fgetc(fp))!=EOF&&(ch!='\n'))
    {
        strbuf_addch(sb,ch);
    }
    if(ferror(fp))return EOF;
    if(ch==EOF&&sb->len==0)return EOF;
    return 0;
}
struct strbuf** strbuf_split_buf(const char* str, size_t len, int terminator, int max)
{
    struct strbuf** part=(struct strbuf**)malloc((len+1)*sizeof(struct strbuf*));
    if(part==NULL)exit(1);
    int start=0;
    int count=0;
    for(int i=0;i<=len;i++)
    {
        if((i==len)||str[i]==terminator&&((count+1<max)||(max<=0)))
        {
            if(i==len&&start==i)break;
            int length=i-start;
            if(i<len)length++;
            struct strbuf* sb=(struct strbuf*)malloc(sizeof(*sb));
            if(sb==NULL)exit(1);
            strbuf_init(sb,length+1);
            strbuf_add(sb,str+start,length);
            part[count]=sb;
            count++;
            start=i+1;
        }
    }
    part[count]=NULL;
    return part;
}
bool strbuf_begin_judge(char* target_str, const char* str, int strlen)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(i>=strlen||str[i]!=target_str[i])
        {
            return false;
        }
    }
    return true;
}
char* strbuf_get_mid_buf(char* target_buf, int begin, int end, int len)
{
    if(target_buf==NULL||begin<0||begin>end||end>len)
    {
        return NULL;
    }
    int n=end-begin;
    char* p=(char*)malloc(n+1);
    if(p==NULL)return NULL;
    for(int i=0;i<n;i++)
    {
        p[i]=target_buf[begin+i];
    }
    p[n]='\0';
    return p;
}
