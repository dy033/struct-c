#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
typedef struct Node    
{ 
	char num[100];
    char name[100];
    char author[100];
    int now;
    int all;

	struct Node  * next;
}Node, *LinkList;
// typedef struct delete    
// { 
// 	char num[1000];
//     char name[1000];
//     char author[1000];
//     int now;
//     int all;
// }deleted;
// void init(LinkList *);
// void in(LinkList *);
// void switchl(LinkList *);
// void switchr(LinkList *);
// int lend(LinkList ,char,int );
// int lend1(LinkList ,char ,int );
// int lend2(LinkList ,char ,int );
// int returnb(LinkList ,char ,int );
// int returnb1(LinkList ,char ,int );
// int returnb2(LinkList ,char ,int );

int init(LinkList &L)
{   
   LinkList L0;
   L=(LinkList)malloc(sizeof(Node)); 
    L0=(LinkList)malloc(sizeof(Node));
    L->next=NULL;
    L0->next=L->next;
    L->next=L0; 
   return 1;
                       
}
int in(LinkList  &L)
{
    LinkList s;
    int c3;
    int flag=1;
 	while(flag) 
	{  s=(LinkList)malloc(sizeof(Node));  
        fflush(stdin);
       printf("请输入书籍书号:") ;
		scanf("%s",&s->num); 
        fflush(stdin);
        printf("请输入书籍书名:") ;
        scanf("%s",&s->name);
        fflush(stdin);
        printf("请输入书籍作者:") ;
        scanf("%s",&s->author);
        fflush(stdin);
        printf("请输入数量:") ;
        scanf("%d",&s->now);
        fflush(stdin);
		
		// s->num=c;
        // s->name=c1;
        // s->author=c2;
        s->all=s->now;
		s->next=L->next;
		L->next=s;	
        if(getchar()!='\n')
          { fflush(stdin);
            flag=0;
            }
	}
    return 1;
}

int lend(LinkList &L,char nu[1000],int i)  //通过书号借阅书籍
{   
    LinkList pre;
	int k;
	pre=L;
	k=0;
	while(pre->next!=NULL&&strcmp(pre->num,nu))	
	{ 
		pre=pre->next; 
	}	
   				
	if(!(pre->next))     
	{
		printf("不存在此书!");
		return 0;
	}
    if(pre->now==0)
    {
      printf("此书已被借完！");
	return 0;  
    }
	pre->now-=i; 
    printf("借阅的书籍信息如下:\n");
    printf("书号\t书名\t作者\t借阅数量\t剩余量\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("成功借出此书!");
	return 1;
}
int lend1(LinkList &L,char nam[1000],int i) //通过书名借出书籍
{
    LinkList pre;
	int k;
	pre=L;
	k=0;
	while(pre->next!=NULL&&strcmp(pre->name,nam))	
	{ 
		pre=pre->next; 
	}								
	if(!(pre->next))     
	{
		printf("不存在此书!");
		return 0;
	}
    if(pre->now==0)
    {
      printf("此书已被借完！");
	return 0;  
    }
	pre->now-=i;        
	printf("借阅的书籍信息如下:\n");
    printf("书号\t书名\t作者\t借阅数量\t剩余量\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("成功借出此书!");
	return 1;
}
int lend2(LinkList L,char aut[1000],int i) //通过作者借出书籍
{
    LinkList pre,pre2;
	int k,b,g=0;
	pre=L;
    pre2=L;
	k=0;
    int a[100]; 
    while(pre->next!=NULL)
    {
        while(strcmp(pre->author,aut))	
        { 
            pre=pre->next; 
            k++;
        }
        if(!(pre->next)&&k=0)     
        {
          printf("不存在此书!");
            return 0;
        }
        a[g]=k;
        g++;
        if(g==1)
        {
            printf("序号\t书号\t书名\t作者\t剩余量\t库存量\n");
        }
        if(pre->now==0)
         {
            g--;  
        }
        printf("%d\t%s\t%s\t%s\t%d\t%d\n",k,pre->num,pre->name,pre->author,pre->now,pre->all);
    }	
    g=0;							
	printf("请选择你要借阅的书籍:");
    scanf("%d",&b);
    while(g<a[b])
        { 
            pre2=pre2->next; 
            g++;
        }
	pre2->now-=i;        
	printf("借阅的书籍信息如下:\n");
    printf("书号\t书名\t作者\t借阅数量\t剩余量\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("成功借出此书!");
	return 1;
    
}

int returnb(LinkList &L,char nu[1000],int i) //通过书号归还书籍
{
    LinkList pre;
	int k;
	pre=L;
	k=0;
    pre=pre->next;
	while(pre->next!=NULL&&strcmp(pre->num,nu))	
	{ 
		pre=pre->next; 
	}								
	if(!(pre->next))     
	{
		 printf("不存在此书!");
		return 0;
	}
    pre=pre->next;
	pre->now+=i;        
	printf("归还的书籍信息如下:\n");
    printf("书号\t书名\t作者\t归还数量\t剩余量\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("成功归还此书!");
	return 1;
}
int returnb1(LinkList &L,char nam[1000],int i) //通过书名归还书籍
{
    LinkList pre;
	int k;
	pre=L;
	k=0;
    pre=pre->next;
	while(pre->next!=NULL&&strcmp(pre->name,nam))	
	{ 
		pre=pre->next; 
	}								
	if(!(pre->next))     
	{
		 printf("不存在此书!");
		return 0;
	}
    pre=pre->next;
	pre->now+=i;        
	printf("归还的书籍信息如下:\n");
    printf("书号\t书名\t作者\t归还数量\t剩余量\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("成功归还此书!");
	return 1;
}
int returnb2(LinkList &L,char aut[1000],int i) //通过作者归还书籍
{
    LinkList pre,pre2;
	int k,b,g;
	pre=L;
    pre2=L;
	k=0;
    g=0;
    int a[1000];
    pre2=pre2->next;
    printf("序号\t书号\t书名\t作者\t剩余量\t库存量\n");
    while(pre->next!=NULL)
    {
        while(pre->next!=NULL&&strcmp(pre->author,aut))	
        { 
            pre=pre->next; 
            k++;
        }
        if(!(pre->next))     
        {
            printf("不存在此书!");
            return 0;
        }
        pre=pre->next;
        a[i]=k;
        g++;
        printf("%d\t%s\t%s\t%s\t%d\t%d\n",k,pre->num,pre->name,pre->author,pre->now,pre->all);
    }	
    g=0;							
	printf("请输入你要归还的书籍：");
    scanf("%d",&b);
    while(g<a[b])
        { 
            pre2=pre2->next; 
            g++;
        }
    pre2=pre2->next;
	pre2->now+=i;        
	printf("归还的书籍信息如下:\n");
    printf("书号\t书名\t作者\t归还数量\t剩余量\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("成功归还此书!");
	return 1;
}
void switchl(LinkList &M)
{
  L0:printf("请选择借阅函数\n"
            "1.书号\n"
            "2.书名\n"
            "3.作者\n");
    int x,i;
    char b[1000];
    scanf("%d",&x);
    fflush(stdin);
    switch(x)
    {
        case 1: printf("请输入借阅书籍书号:");
                gets(b);
                fflush(stdin);
                printf("请输入借阅数量:");
                scanf("%d",&i);
                fflush(stdin);
                lend(M,b,i);
                break;
        case 2:  printf("请输入借阅书籍书名:");
                gets(b);
                fflush(stdin);
                printf("请输入借阅数量:");
                scanf("%d",&i);
                fflush(stdin);
                lend1(M,b,i);
                break;
        case 3:  printf("请输入借阅书籍作者:");
                gets(b);
                fflush(stdin);
                printf("请输入借阅数量:");
                scanf("%d",&i);
                fflush(stdin);
                lend2(M,b,i);
                break;
        default:printf("不存在此操作!!!");
                goto L0;
    }

}
void switchr(LinkList &M)
{
  L1:printf("请选择还书方式\n"
            "1.书名\n"
            "2.书号\n"
            "3.作者\n");
    int x,i;
    char b[1000];
    scanf("%d",&x);
    fflush(stdin);
    switch(x)
    {
        case 1: printf("请输入归还书籍书号:");
                gets(b);
                fflush(stdin);
                printf("请输入归还数量:");
                scanf("%d",&i);
                fflush(stdin);
                returnb(M,b,i);
                break;
        case 2: printf("请输入归还书籍书名:");
                gets(b);
                fflush(stdin);
                printf("请输入归还数量:");
                scanf("%d",&i);
                fflush(stdin);
                returnb1(M,b,i);
                break;
        case 3:  printf("请输入归还书籍作者:");
                gets(b);
                fflush(stdin);
                printf("请输入归还数量:");
                scanf("%d",&i);
                fflush(stdin);
                returnb2(M,b,i);
                break;
        default:printf("不存在此操作!!!");
                goto L1;
    }

}
int main()
{
    int a;
    LinkList Ctr;
    init(Ctr);
    while(1)
    {
        printf("\t\t欢迎来到海南大学图书管理系统\n");
        printf("\t\t1.采编入库\n"
               "\t\t2.借阅\n"
               "\t\t3.归还\n"
               "\t\t按Ctrl+C结束运行\n");
        printf("\t\t请选择你的操作:");
        scanf("%d",&a);
        fflush(stdin);
        switch(a)
        {
            case 1: in(Ctr);
                    break;
            case 2: switchl(Ctr);
                      break;
            case 3: switchr(Ctr);
                      break;
            default: printf("不存在此操作!!!") ;
                     system("cls");
                     break;
        }
        
    }       
}