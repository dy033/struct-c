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
       printf("�������鼮���:") ;
		scanf("%s",&s->num); 
        fflush(stdin);
        printf("�������鼮����:") ;
        scanf("%s",&s->name);
        fflush(stdin);
        printf("�������鼮����:") ;
        scanf("%s",&s->author);
        fflush(stdin);
        printf("����������:") ;
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

int lend(LinkList &L,char nu[1000],int i)  //ͨ����Ž����鼮
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
		printf("�����ڴ���!");
		return 0;
	}
    if(pre->now==0)
    {
      printf("�����ѱ����꣡");
	return 0;  
    }
	pre->now-=i; 
    printf("���ĵ��鼮��Ϣ����:\n");
    printf("���\t����\t����\t��������\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("�ɹ��������!");
	return 1;
}
int lend1(LinkList &L,char nam[1000],int i) //ͨ����������鼮
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
		printf("�����ڴ���!");
		return 0;
	}
    if(pre->now==0)
    {
      printf("�����ѱ����꣡");
	return 0;  
    }
	pre->now-=i;        
	printf("���ĵ��鼮��Ϣ����:\n");
    printf("���\t����\t����\t��������\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("�ɹ��������!");
	return 1;
}
int lend2(LinkList L,char aut[1000],int i) //ͨ�����߽���鼮
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
          printf("�����ڴ���!");
            return 0;
        }
        a[g]=k;
        g++;
        if(g==1)
        {
            printf("���\t���\t����\t����\tʣ����\t�����\n");
        }
        if(pre->now==0)
         {
            g--;  
        }
        printf("%d\t%s\t%s\t%s\t%d\t%d\n",k,pre->num,pre->name,pre->author,pre->now,pre->all);
    }	
    g=0;							
	printf("��ѡ����Ҫ���ĵ��鼮:");
    scanf("%d",&b);
    while(g<a[b])
        { 
            pre2=pre2->next; 
            g++;
        }
	pre2->now-=i;        
	printf("���ĵ��鼮��Ϣ����:\n");
    printf("���\t����\t����\t��������\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("�ɹ��������!");
	return 1;
    
}

int returnb(LinkList &L,char nu[1000],int i) //ͨ����Ź黹�鼮
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
		 printf("�����ڴ���!");
		return 0;
	}
    pre=pre->next;
	pre->now+=i;        
	printf("�黹���鼮��Ϣ����:\n");
    printf("���\t����\t����\t�黹����\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("�ɹ��黹����!");
	return 1;
}
int returnb1(LinkList &L,char nam[1000],int i) //ͨ�������黹�鼮
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
		 printf("�����ڴ���!");
		return 0;
	}
    pre=pre->next;
	pre->now+=i;        
	printf("�黹���鼮��Ϣ����:\n");
    printf("���\t����\t����\t�黹����\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("�ɹ��黹����!");
	return 1;
}
int returnb2(LinkList &L,char aut[1000],int i) //ͨ�����߹黹�鼮
{
    LinkList pre,pre2;
	int k,b,g;
	pre=L;
    pre2=L;
	k=0;
    g=0;
    int a[1000];
    pre2=pre2->next;
    printf("���\t���\t����\t����\tʣ����\t�����\n");
    while(pre->next!=NULL)
    {
        while(pre->next!=NULL&&strcmp(pre->author,aut))	
        { 
            pre=pre->next; 
            k++;
        }
        if(!(pre->next))     
        {
            printf("�����ڴ���!");
            return 0;
        }
        pre=pre->next;
        a[i]=k;
        g++;
        printf("%d\t%s\t%s\t%s\t%d\t%d\n",k,pre->num,pre->name,pre->author,pre->now,pre->all);
    }	
    g=0;							
	printf("��������Ҫ�黹���鼮��");
    scanf("%d",&b);
    while(g<a[b])
        { 
            pre2=pre2->next; 
            g++;
        }
    pre2=pre2->next;
	pre2->now+=i;        
	printf("�黹���鼮��Ϣ����:\n");
    printf("���\t����\t����\t�黹����\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("�ɹ��黹����!");
	return 1;
}
void switchl(LinkList &M)
{
  L0:printf("��ѡ����ĺ���\n"
            "1.���\n"
            "2.����\n"
            "3.����\n");
    int x,i;
    char b[1000];
    scanf("%d",&x);
    fflush(stdin);
    switch(x)
    {
        case 1: printf("����������鼮���:");
                gets(b);
                fflush(stdin);
                printf("�������������:");
                scanf("%d",&i);
                fflush(stdin);
                lend(M,b,i);
                break;
        case 2:  printf("����������鼮����:");
                gets(b);
                fflush(stdin);
                printf("�������������:");
                scanf("%d",&i);
                fflush(stdin);
                lend1(M,b,i);
                break;
        case 3:  printf("����������鼮����:");
                gets(b);
                fflush(stdin);
                printf("�������������:");
                scanf("%d",&i);
                fflush(stdin);
                lend2(M,b,i);
                break;
        default:printf("�����ڴ˲���!!!");
                goto L0;
    }

}
void switchr(LinkList &M)
{
  L1:printf("��ѡ���鷽ʽ\n"
            "1.����\n"
            "2.���\n"
            "3.����\n");
    int x,i;
    char b[1000];
    scanf("%d",&x);
    fflush(stdin);
    switch(x)
    {
        case 1: printf("������黹�鼮���:");
                gets(b);
                fflush(stdin);
                printf("������黹����:");
                scanf("%d",&i);
                fflush(stdin);
                returnb(M,b,i);
                break;
        case 2: printf("������黹�鼮����:");
                gets(b);
                fflush(stdin);
                printf("������黹����:");
                scanf("%d",&i);
                fflush(stdin);
                returnb1(M,b,i);
                break;
        case 3:  printf("������黹�鼮����:");
                gets(b);
                fflush(stdin);
                printf("������黹����:");
                scanf("%d",&i);
                fflush(stdin);
                returnb2(M,b,i);
                break;
        default:printf("�����ڴ˲���!!!");
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
        printf("\t\t��ӭ�������ϴ�ѧͼ�����ϵͳ\n");
        printf("\t\t1.�ɱ����\n"
               "\t\t2.����\n"
               "\t\t3.�黹\n"
               "\t\t��Ctrl+C��������\n");
        printf("\t\t��ѡ����Ĳ���:");
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
            default: printf("�����ڴ˲���!!!") ;
                     system("cls");
                     break;
        }
        
    }       
}