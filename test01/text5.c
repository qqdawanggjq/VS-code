// #include<stdio.h>
// int main()
// {
//     while(1)
//     {
//         char cho;
//         printf("\nEnter the operation of your choice:\n");
//         printf("a. add       s. subtract\n");
//         printf("m. multiply  d. divide\n");
//         printf("q. quit\n");
//         scanf("%c",cho);
//         switch(cho)
//         {
//             case a:
//             {
//                 printf("Enter first number: ");
//                 float one,two;
//                 if((scanf("%lf",one))!=1)
//                 {
//                     printf("请重新输入：");
//                     int ch;
//                     while((ch=getchar())!='\n'&&ch!=EOF)
//                     scanf("%lf",one);
//                 }
//                 printf("Enter second number: ");
//                 if((scanf("%lf",two))!=1)
//                 {
//                     printf("请重新输入：");
//                     int ch;
//                     while((ch=getchar())!='\n'&&ch!=EOF)
//                     scanf("%lf",two);
//                 }
//                 printf("%f + %f = %f\n",one,two,one+two);
//             }
//             case s:
//             {
//                 printf("Enter first number: ");
//                 float one,two;
//                 if((scanf("%lf",one))!=1)
//                 {
//                     printf("请重新输入：");
//                     int ch;
//                     while((ch=getchar())!='\n'&&ch!=EOF)
//                     scanf("%lf",one);
//                 }
//                 printf("Enter second number: ");
//                 if((scanf("%lf",two))!=1)
//                 {
//                     printf("请重新输入：");
//                     int ch;
//                     while((ch=getchar())!='\n'&&ch!=EOF)
//                     scanf("%lf",two);
//                 }
//                 printf("%f + %f = %f\n",one,two,one+two);
//             }
//             case a:
//             {
//                 printf("Enter first number: ");
//                 float one,two;
//                 if((scanf("%lf",one))!=1)
//                 {
//                     printf("请重新输入：");
//                     int ch;
//                     while((ch=getchar())!='\n'&&ch!=EOF)
//                     scanf("%lf",one);
//                 }
//                 printf("Enter second number: ");
//                 if((scanf("%lf",two))!=1)
//                 {
//                     printf("请重新输入：");
//                     int ch;
//                     while((ch=getchar())!='\n'&&ch!=EOF)
//                     scanf("%lf",two);
//                 }
//                 printf("%f + %f = %f\n",one,two,one+two);
//             }
//             case a:
//             {
//                 printf("Enter first number: ");
//                 float one,two;
//                 if((scanf("%lf",one))!=1)
//                 {
//                     printf("请重新输入：");
//                     int ch;
//                     while((ch=getchar())!='\n'&&ch!=EOF)
//                     scanf("%lf",one);
//                 }
//                 printf("Enter second number: ");
//                 if((scanf("%lf",two))!=1)
//                 {
//                     printf("请重新输入：");
//                     int ch;
//                     while((ch=getchar())!='\n'&&ch!=EOF)
//                     scanf("%lf",two);
//                 }
//                 printf("%f + %f = %f\n",one,two,one+two);
//             }
//         }

//     }
// }
// #include<stdio.h>
// #include<stdlib.h>
// typedef struct result
// {
//     int* arr;
//     int len;
// }result;
// void your_sort(int* arr1,int len1,int* arr2,int len2,result* res)
// {
//     res->len=len1+len2;
//     res->arr=(int*)malloc(res->len*sizeof(int));
//     for(int i=0;i<len1;i++)
//     {
//         res->arr[i]=arr1[i];
//     }
//     for(int i=0;i<len2;i++)
//     {
//         res->arr[len1+i]=arr2[i];
//     }
//     for(int i=0;i<res->len-1;i++)
//     {
//         for(int j=0;j<res->len-1-i;j++)
//         {
//             if(res->arr[j]>res->arr[j+1])
//             {
//                 int t=res->arr[j+1];
//                 res->arr[j+1]=res->arr[j];
//                 res->arr[j]=t;
//             }
//         }
//     }
//     int slow=0;
//     for(int fast=1;fast<res->len;fast++)
//     {
//         if(res->arr[fast]!=res->arr[slow])
//         {
//             slow++;
//             res->arr[slow]=res->arr[fast];
//         }
//     }
//     res->len=slow+1;
// }
// int main() {
//     int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 10};
//     int arr2[] = {2, 1, 4, 3, 9, 6, 8};
//     int len1 = sizeof(arr1) / sizeof(arr1[0]);
//     int len2 = sizeof(arr2) / sizeof(arr2[0]);

//     result result;
//     your_sort(arr1, len1, arr2, len2, &result);
//     for (int i = 0; i < result.len; i++) {
//         printf("%d ", result.arr[i]);
//     }
//     free(result.arr);
//     return 0;
// }
// struct ddd * p=head;
// head=head->next;
// free(p);
// int isPal(int n)
// {
//     int x=n,reverse=0;
//     while(x>0)
//     {
//         reverse=reverse*10+x%10;
//         x=x/10;
//     }
//     return n==reverse;
// }
// #include<stdio.h>
// int isPrime(int n)
// {
//     if(n<2)return 0;
//     //先排除 2 和 3 以及它们的倍数
//     if(n%2==0)return n==2;
//     if(n%3==0)return n==3;
//     //i*i<=n等价于i<=n/i
//     //可以避免i*i越界
//     for(int i=5;i<n/i;i+=6)
//     {
//         if(n%i==0||n%(i+2)==0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

// int main()
// {
//     int a,b;
//     scanf("%d%d",&a,&b);
//     //单独处理5 7 11
//     if(a<=5&&b>=5)
//     {
//         printf("5\n");
//     }
//     if(a<=7&&b>=7)
//     {
//         printf("7\n");
//     }
//     if(a<=11&&b>=11)
//     {
//         printf("11\n");
//     }
//     //构造三位、五位、七位的回文数
//     for(int i=10;i<9999;i++)
//     {
//         int n=i;
//         int x=i/10;
//         while(x>0)
//         {
//             n=n*10+x%10;
//             x=x/10;
//         }
//         if(n>b)break;
//         if(n<a||n%2==0||n%5==0)continue;
//         if(isPrime(n))
//         {
//             printf("%d\n",n);
//         }
//     }
//     return 0;
// }
// for(int i=0;i<=len;i++)
//     {
//         if((i==len)||str[i]==terminator&&((count+1<max)||(max<=0)))
//         {
//             if(i==len&&start==i)break;
//             int length=i-start;
//             if(i<len)length++;
//             struct strbuf* sb=(struct strbuf*)malloc(sizeof(*sb));
//             if(sb==NULL)exit(1);
//             strbuf_init(sb,length+1);
//             strbuf_add(sb,str+start,length);
//             part[count]=sb;
//             count++;
//             start=i+1;
//         }
//     }
//     part[count]=NULL;
// struct strbuf** strbuf_split_buf(const char* str, size_t len, int terminator, int max)
// {
//     struct strbuf** part=(struct strbuf**)malloc((len+1)*sizeof(struct strbuf*));
//     if(part==NULL)exit(1);
//     int start=0;
//     int count=0;
//     while(start<len&&(max<=0||count<max))
//     {
        
//         int end=start;
//         if(max<=0||count+1<max)
//         {
//             while(end<len&&str[end]!=terminator)
//             {
//                 end++;
//             }
//         }
//         else
//         {
//             end=len;
//         }
//         struct strbuf* sb=(struct strbuf*)malloc(sizeof(*sb));
//         if(sb==NULL)exit(1);
//         strbuf_init(sb,end-start+1);
//         strbuf_add(sb,str+start,end-start);
//         part[count]=sb;
//         count++;
//         start=end+1;
//     }
//     part[count]=NULL;
//     return part;
// }
// #include<stdio.h>
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=n;i>=0;i--)
//     {
//         int xi;
//         scanf("%d",&xi);
//         if(n==0)
//         {
//             printf("%d",xi);
//             break;
//         }
//         if(xi==0)continue;
//         if(i==0)
//         {
//             if(xi>0)
//             {
//                 printf("+%d",xi);
//             }
//             else if(xi<0)
//             {
//                 printf("%d",xi);
//             }
//         }
//         else if(i==1)
//         {
//             if(n==1)
//             {
//                 if(xi==1)
//                 {
//                     printf("x");
//                 }
//                 else if(xi==-1)
//                 {
//                     printf("-x");
//                 }
//                 else
//                 {
//                 printf("%dx",xi);
//                 }
//             }
//             else 
//             {
//                 if(xi>0)
//                 {   
//                     if(xi==1)
//                     {
//                         printf("+x");
//                     }
//                     else
//                     {
//                     printf("+%dx",xi);
//                     }
//                 }
//                 else if(xi<0)
//                 {
//                     if(xi==-1)
//                     {
//                         printf("-x");
//                     }
//                     else
//                     {
//                     printf("%dx",xi);
//                     }
//                 }
//             }
//         }
//         else
//         {
//         if(xi>0)
//         {
//             if(xi==1&&i!=n)printf("+x^%d",i);
//             else if(xi==1&&i==n)printf("x^%d",i);
//             else
//             {
//             if(i==n)
//             {
//                 printf("%dx^%d",xi,i);
//             }
//             else
//             {
//                 printf("+%dx^%d",xi,i);
//             }
//             }
//         }
//         else if(xi<0)
//         {
//             if(xi==-1)printf("-x^%d",i);
//             else printf("%dx^%d",xi,i);
//         }
//         }
//     }
//     return 0;
// }
//acv