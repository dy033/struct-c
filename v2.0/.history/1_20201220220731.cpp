#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
typedef struct Node    
{ 
	char *num;
    char *name;
    char *author;
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

void init(LinkList &L)
{   
   
   L=(LinkList)malloc(sizeof(Node)); 
   L->next=NULL;  
                       
}
void in(LinkList  &L)
{
    LinkList s;
	char n,c[1000],c1[1000],c2[1000];
    int c3;
	int flag=1;
 	while(flag)   
	{
       printf("�������鼮���:") ;
		gets(c); 
        fflush(stdin);
        printf("�������鼮����:") ;
        gets(c1);
        fflush(stdin);
        printf("�������鼮����:") ;
        gets(c2);
        fflush(stdin);
        printf("����������:") ;
        scanf("%d",&c3);
        fflush(stdin);
    
		s=(LinkList)malloc(sizeof(LinkList)); 
		s->num=c;
        s->name=c1;
        s->author=c2;
        s->now=c3;
        s->all=c3;
		s->next=L->next;
		L->next=s;
        printf("%s\n",s->num);
        printf("%s\n",s->name);
        printf("%s\n",s->author);
         printf("%d\n",s->now);
          printf("%d\n",s->all);
		if((n=getchar())!='\n')
		    flag=0;
	}
}

int lend(LinkList &L,char nu[1000],int i)  //ͨ����Ž����鼮
{
    LinkList pre;
	int k;
	pre=L;
	k=0;
	while(!strcmp(pre->num,nu))	
	{ 
		pre=pre->next; 
	}								
	if(!(pre->next))     
	{
		printf("�����ڴ���!");
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
	while(!strcmp(pre->name,nam))	
	{ 
		pre=pre->next; 
	}								
	if(!(pre->next))     
	{
		printf("�����ڴ���!");
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
    int a[1000];
    printf("���\t���\t����\t����\tʣ����\t�����\n");
    while(pre->next!=NULL)
    {
        while(strcmp(pre->author,aut))	
        { 
            pre=pre->next; 
            k++;
        }
        if(!(pre->next))     
        {
          printf("�����ڴ���!");
            return 0;
        }
    
        a[g]=k;
        g++;
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
	while(!strcmp(pre->num,nu))	
	{ 
		pre=pre->next; 
	}								
	if(!(pre->next))     
	{
		 printf("�����ڴ���!");
		return 0;
	}
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
	while(!strcmp(pre->name,nam))	
	{ 
		pre=pre->next; 
	}								
	if(!(pre->next))     
	{
		 printf("�����ڴ���!");
		return 0;
	}
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
    printf("���\t���\t����\t����\tʣ����\t�����\n");
    while(pre->next!=NULL)
    {
        while(strcmp(pre->author,aut))	
        { 
            pre=pre->next; 
            k++;
        }
        if(!(pre->next))     
        {
            printf("�����ڴ���!");
            return 0;
        }
    
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
	pre2->now+=i;        
	printf("�黹���鼮��Ϣ����:\n");
    printf("���\t����\t����\t�黹����\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);      
	printf("�ɹ��黹����!");
	return 1;
}
void switchl(LinkList &M)
{
  L1:printf("��ѡ����ĺ���\n"
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
                goto L1;
    }

}
void switchr(LinkList &M)
{
  L1:printf("��ѡ���鷽ʽ\n"
            "1.����\nn"
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
    while(1)
    {
        LinkList Ctr;
        init(Ctr);
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