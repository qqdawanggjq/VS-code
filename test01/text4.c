// #include<stdio.h>
// #include<string.h>
// int main(int argc,char*argv[])
// {
//     if(argc!=3)
//     {
//         printf("Usage: %s source target\n",argv[0]);
//         return 1;
//     }
//     if(strcmp(argv[1],argv[2])==0)
//     {
//         printf("Source and target must be different\n");
//         return 1;
//     }
//     FILE* fp1=fopen(argv[1],"rb");
//     if(fp1==NULL)
//     {
//         printf("Cannot open source file\n");
//         return 1;
//     }
//     FILE* fp2=fopen(argv[2],"wb");
//     if(fp2==NULL)
//     {
//         printf("Cannot open target file\n");
//         fclose(fp1);
//         return 1;
//     }
//     int ch,ok=1;
//     while((ch=fgetc(fp1))!=EOF)
//     {
//         if(fputc(ch,fp2)==EOF)
//         {
//             ok=0;
//             break;
//         }
//     }
//     if(ferror(fp1))ok=0;
//     fclose(fp1);
//     if(fclose(fp2)==EOF)ok=0;
//     if(!ok)
//     {
//         printf("File copy failed\n");
//         return 1;
//     }
//     printf("File copied successfully\n");
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     char filename[300];
//     long pos;
//     int ch;
//     printf("Enter filename: ");
//     scanf("%299s",filename);
//     FILE* fp=fopen(filename,"rb");
//     if(fp==NULL)
//     {
//         printf("Cannot open file\n");
//         return 1;
//     }
//     while(1)
//     {
//         printf("Enter position: ");
//         if(scanf("%ld",&pos)!=1||pos<0)break;
//         if(fseek(fp,pos,SEEK_SET)!=0)
//         {
//             printf("Cannot seek to position\n");
//             continue;
//         }
//         while((ch=fgetc(fp))!=EOF&&ch!='\n')
//         {
//             putchar(ch);
//         }
//         putchar('\n');
//         fclose(fp);
//         return 0;
//     }
// }
// #include<stdio.h>
// #include<string.h>
// int main(int argc,char* argv[])
// {
//     if(argc!=3)
//     {
//         printf("Usage:%s word filename\n",argv[0]);
//         return 1;
//     }
//     FILE* fp=fopen(argv[2],"r");
//     if(fp==NULL)
//     {
//         printf("Cannot open file\n");
//         return 1;
//     }
//     char line[257];
//     while(fgets(line,sizeof(line),fp)!=NULL)
//     {
//         if(strstr(line,argv[1])!=NULL)
//         {
//             printf("%s",line);
//         }
//     }
//     fclose(fp);
//     return 0;
// }
// #include<stdio.h>
// struct name
// {
//     char firstname[20];
//     char midname[20];
//     char lastname[20];
// };
// struct student
// {
//     char id[30];
//     struct name name;
// };
// void pri1(struct student* people)
// {
//     printf("%s,",people->name.firstname);
//     if(people->name.midname[0]!='\0')
//     {
//         printf("%c ",people->name.midname[0]);
//     }
//     printf("%s.--",people->name.lastname);
//     printf("%s\n",people->id);
// }
// void pri2(struct student peoples)
// {
//     printf("%s,",peoples.name.firstname);
//     if(peoples.name.midname[0]!='\0')
//     {
//         printf("%c ",peoples.name.midname[0]);
//     }
//     printf("%s.--",peoples.name.lastname);
//     printf("%s\n",peoples.id);
// }
// int main()
// {
//     struct student arr[5];
//     for(int i=0;i<5;i++)
//     {
//         scanf("%19s%19s%19s%29s",arr[i].name.firstname,
//             arr[i].name.midname,arr[i].name.lastname,arr[i].id);
//         pri1(&arr[i]);
//         pri2(arr[i]);    
//     }
//     return 0;
// }
// #INCLUDE<STDIO.H>
// #include<stdio.h>
// struct name
// {
//     char xing[30];
//     char ming[30];
// };
// struct student
// {
//     struct name name;
//     double grade[3];
//     double aveage;
// };
// void entergrade(struct student s[])
// {
//     for(int i=0;i<4;i++)
//     {
//         scanf("%lf%lf%lf",&s[i].grade[0],
//         &s[i].grade[1],&s[i].grade[2]);    
//     }
// }
// void ave(struct student s[])
// {
//     for(int i=0;i<4;i++)
//     {
//         s[i].aveage=(s[i].grade[0]+s[i].grade[1]
//             +s[i].grade[2])/3;
//     }
// }
// void pri(struct student s[])
// {
//     for(int i=0;i<4;i++)
//     {
//         printf("%s %s %f %f %f %f\n",
//         s[i].name.xing,s[i].name.ming,s[i].grade[0],
//         s[i].grade[1],s[i].grade[2],s[i].aveage);
//     }
//     int aveave=(s[0].aveage+s[1].aveage+s[2].aveage+s[3].aveage)/4;
//     printf("%f %f\n",aveave,aveave);
// }
// int main()
// {
//     struct student s[4]=
//     {
//         {{"Zhang","San"},{0},0},
//         {{"Li","Si"},{0},0},
//         {{"Wang","Wu"},{0},0},
//         {{"Zhao","Liu"},{0},0}
//     };
//     entergrade(s);
//     ave(s);
//     pri(s);
//     return 0;
// }
// #include<stdio.h>
// #include<math.h>
// double square(double x)
// {
//     double aim=x*x;
//     return aim;
// }
// void transform(double source[],double target[],int n,double (*hanshu)(double))
// {
//     for(int i=0;i<n;i++)
//     {
//         target[i]=hanshu(source[i]);
//     }
// }
// int main()
// {
//     double source[5]={0,1,2,3,4};
//     double target[5];
//     transform(source,target,5,sin);
//     for(int i=0;i<5;i++)
//     {
//         printf("%.3f ",target[i]);
//     }
//     printf("\n");
//     transform(source,target,5,square);
//     for(int i=0;i<5;i++)
//     {
//         printf("%.3f ",target[i]);
//     }
//     printf("\n");
//     return 0;
// }
// #include<stdio.h>
// int trans(char *s)
// {
//     int num=0;
//     while(*s!='\0')
//     {
//         num=(num<<1)+(*s-'0');
//         s++;
//     }
//     return num;
// }
// int main()
// {
//     char s[1000];
//     while(scanf("%s",s)!=EOF)
//     {
//     int num=trans(s);
//     printf("%d",num);
//     }
//     return 0;
// }
// #include<stdio.h>
// int count(int x)
// {
//     unsigned int n=(unsigned int)x;
//     int num=0;
//     while(n!=0)
//     {
//         if(n&1)num++;
//         n=n>>1;
//     }
//     return num;
// }
// int main()
// {
//     int x;
//     scanf("%d",&x);
//     int n=count(x);
//     printf("%d\n",n);
//     return 0;
// }
// #include<stdio.h>
// #include<limits.h>
// unsigned int rotate(unsigned int n,int move)
// {
//     int len=sizeof(unsigned int)*CHAR_BIT;
//     move=move%len;
//     if(move==0)return n;
//     unsigned int ns=((n<<move)|(n>>(len-move)));
//     return ns;
// }
// int main()
// {
//     unsigned int n;
//     int move;
//     scanf("%u%d",&n,&move);
//     unsigned int x=rotate(n,move);
//     printf("%u",x);
//     return 0;
// }
// #include<stdio.h>
// #include<math.h>
// struct ji
// {
//     double mo;
//     double jiao;
// };
// struct zhijiao
// {
//     double x;
//     double y;
// };
// struct zhijiao trans(struct ji ori)
// {
//     struct zhijiao aim;
//     double pi=acos(-1.0);
//     aim.x=ori.mo*cos(ori.jiao*(pi/180));
//     aim.y=ori.mo*sin(ori.jiao*(pi/180));
//     return aim;
// }
// int main()
// {
//     struct ji ori;
//     while(scanf("%lf%lf",&ori.mo,&ori.jiao)==2)
//     {
//         struct zhijiao aim=trans(ori);
//         printf("%f %f\n",aim.x,aim.y);
//     }
//     return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>
// void freedom(int arr[],int n,int select)
// {
//     for(int i=0;i<select;i++)
//     {
//         int j=rand()%(n-i);
//         printf("%d ",arr[j]);
//         int t=arr[j];
//         arr[j]=arr[n-1-i];
//         arr[n-1-i]=t;
//     }
// }
// int main()
// {
//     srand((unsigned int)time(NULL));
//     int arr[100];
//     int i=0;
//     while(i<100&&scanf("%d",&arr[i])==1)
//     {
//         i++;
//     }
//     printf("请输入选取次数：");
//     int select;
//     scanf("%d",&select);
//     freeodm(arr,i,select);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdarg.h>

// void show_array(const double ar[], int n);
// double * new_d_array(int n, ...);
// int main()
// {
//     double * p1;
//     double * p2;

//     p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
//     p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
//     show_array(p1, 5);
//     show_array(p2, 4);
//     free(p1);
//     free(p2);

//     return 0;
// }
// double * new_d_array(int n, ...)
// {
//     double* p=(double*)malloc(sizeof(double)*n);
//     va_list ap;
//     va_start(ap,n);
//     for(int i=0;i<n;i++)
//     {
//         p[i]=va_arg(ap,double);
//     }
//     va_end(ap);
//     return p;
// }
// void show_array(const double ar[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         printf("%.2f",ar[i]);
//     }
//     printf("\n");
// }