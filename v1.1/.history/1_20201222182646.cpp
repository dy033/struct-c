#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXSIZE 100
typedef struct Node
{
    char num[MAXSIZE];
    char name[MAXSIZE];
    char author[MAXSIZE];
    int now;
    int all;

    struct Node *next;
} Node, *LinkList;
typedef struct
{
    char name[MAXSIZE];
    char id[MAXSIZE];
    char passwd[MAXSIZE];
} INF;
INF inf[MAXSIZE];
// typedef struct delete
// {
// 	char num[MAXSIZE];
//     char name[MAXSIZE];
//     char author[MAXSIZE];
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
    L = (LinkList)malloc(sizeof(Node));
    L0 = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    L0->next = L->next;
    L->next = L0;
    return 1;
}
int in(LinkList &L)
{
    LinkList s;
    int c3;
    int flag = 1;
    while (flag)
    {
        s = (LinkList)malloc(sizeof(Node));
        fflush(stdin);
        printf("请输入书籍书号:");
        scanf("%s", &s->num);
        fflush(stdin);
        printf("请输入书籍书名:");
        scanf("%s", &s->name);
        fflush(stdin);
        printf("请输入书籍作者:");
        scanf("%s", &s->author);
        fflush(stdin);
        printf("请输入数量:");
        scanf("%d", &s->now);
        fflush(stdin);
        printf("是否继续录入书籍，若继续录入书籍请回车，否则输入任意字符回车：");

        // s->num=c;
        // s->name=c1;
        // s->author=c2;
        s->all = s->now;
        s->next = L->next;
        L->next = s;
        if (getchar() != '\n')
        {
            fflush(stdin);
            flag = 0;
        }
    }
    return 1;
}
int show(LinkList &L)
{
    LinkList pre;
    int k = 0;
    pre = L;
    int a[MAXSIZE];
    printf("现有的的书籍信息如下:\n");
    printf("书号\t书名\t作者\t剩余量\t库存量\n");
    while (pre->next->next != NULL)
    {
        pre = pre->next;
        printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        k++;
    }
    if (k == 0)
    {
        printf("图书馆里没有书，请采编书籍入库\n");
    }
    return 1;
}
int lend(LinkList &L, char nu[MAXSIZE], int i) //通过书号借阅书籍
{
    LinkList pre;
    int k;
    pre = L;
    k = 0;
    while (pre->next != NULL && strcmp(pre->num, nu))
    {
        pre = pre->next;
    }

    if (!(pre->next))
    {
        printf("不存在此书!");
        return 0;
    }
    if (pre->now == 0)
    {
        printf("此书已被借完！");
        return 0;
    }
    pre->now -= i;
    printf("借阅的书籍信息如下:\n");
    printf("书号\t书名\t作者\t借阅数量\t剩余量\n");
    printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("成功借出此书!");
    return 1;
}
int lend1(LinkList &L, char nam[MAXSIZE], int i) //通过书名借出书籍
{
    LinkList pre;
    int k;
    pre = L;
    k = 0;
    while (pre->next != NULL && strcmp(pre->name, nam))
    {
        pre = pre->next;
    }
    if (!(pre->next))
    {
        printf("不存在此书!");
        return 0;
    }
    if (pre->now == 0)
    {
        printf("此书已被借完！");
        return 0;
    }
    pre->now -= i;
    printf("借阅的书籍信息如下:\n");
    printf("书号\t书名\t作者\t借阅数量\t剩余量\n");
    printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("成功借出此书!");
    return 1;
}
// int lend2(LinkList L,char aut[MAXSIZE],int i) //通过作者借出书籍
// {
//     LinkList pre,pre2;
//     int k=0;
// 	int b,g=0;
// 	pre=L;
//     pre2=L;

//     int a[MAXSIZE];
//     while(pre->next!=NULL)
//     {
//         while(!strcmp(pre->author,aut))
//         {
//             pre=pre->next;
//             ++k;
//         }
//         a[g]=k;
//         g++;
//         if(!(pre->next)&&g==0)
//         {
//           printf("不存在此书!");
//             return 0;
//         }
//         if(g==1)
//         {
//             printf("序号\t书号\t书名\t作者\t剩余量\t库存量\n");
//         }
//         if(pre->now==0)
//          {
//             g--;
//         }
//         printf("%d\t%s\t%s\t%s\t%d\t%d\n",g,pre->num,pre->name,pre->author,pre->now,pre->all);
//         pre=pre->next;
//     }
//     g=0;
// 	printf("请选择你要借阅的书籍:");
//     scanf("%d",&b);
//     while(g<a[b-1])
//         {
//             pre2=pre2->next;
//             g++;
//         }
// 	pre2->now-=i;
// 	printf("借阅的书籍信息如下:\n");
//     printf("书号\t书名\t作者\t借阅数量\t剩余量\n");
//     printf("%s\t%s\t%s\t%d\t%d\n",pre2->num,pre2->name,pre2->author,i,pre2->now);
// 	printf("成功借出此书!");
// 	return 1;

// }

int returnb(LinkList &L, char nu[MAXSIZE], int i) //通过书号归还书籍
{
    LinkList pre;
    int k;
    pre = L;
    k = 0;

    while (pre->next != NULL && strcmp(pre->num, nu))
    {
        pre = pre->next;
    }
    if (!(pre->next))
    {
        printf("不存在此书!");
        return 0;
    }

    pre->now += i;
    printf("归还的书籍信息如下:\n");
    printf("书号\t书名\t作者\t归还数量\t剩余量\n");
    printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("成功归还此书!");
    return 1;
}
int returnb1(LinkList &L, char nam[MAXSIZE], int i) //通过书名归还书籍
{
    LinkList pre;
    int k;
    pre = L;
    k = 0;

    while (pre->next != NULL && strcmp(pre->name, nam))
    {
        pre = pre->next;
    }
    if (!(pre->next))
    {
        printf("不存在此书!");
        return 0;
    }

    pre->now += i;
    printf("归还的书籍信息如下:\n");
    printf("书号\t书名\t作者\t归还数量\t剩余量\n");
    printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("成功归还此书!");
    return 1;
}
// int returnb2(LinkList &L,char aut[MAXSIZE],int i) //通过作者归还书籍
// {
//     LinkList pre,pre2;
// 	int k,b,g;
// 	pre=L;
//     pre2=L;
// 	k=0;
//     g=0;
//     int a[MAXSIZE];
//     printf("序号\t书号\t书名\t作者\t剩余量\t库存量\n");
//     while(pre->next!=NULL)
//     {
//         while(pre->next!=NULL&&strcmp(pre->author,aut))
//         {
//             pre=pre->next;
//             k++;
//         }
//         if(!(pre->next))
//         {
//             printf("不存在此书!");
//             return 0;
//         }

//         a[i]=k;
//         g++;
//         printf("%d\t%s\t%s\t%s\t%d\t%d\n",k,pre->num,pre->name,pre->author,pre->now,pre->all);
//     }
//     g=0;
// 	printf("请输入你要归还的书籍：");
//     scanf("%d",&b);
//     while(g<a[b])
//         {
//             pre2=pre2->next;
//             g++;
//         }

// 	pre2->now+=i;
// 	printf("归还的书籍信息如下:\n");
//     printf("书号\t书名\t作者\t归还数量\t剩余量\n");
//     printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);
// 	printf("成功归还此书!");
// 	return 1;
// }
void switchl(LinkList &M)
{
L0:
    printf("借阅方式\n"
           "1.书号\n"
           "2.书名\n"
           "3.作者\n");
    int x, i;
    char b[MAXSIZE];
    printf("请选择借阅方式:");
    scanf("%d", &x);
    fflush(stdin);
    switch (x)
    {
    case 1:
        printf("请输入借阅书籍书号:");
        gets(b);
        fflush(stdin);
        printf("请输入借阅数量:");
        scanf("%d", &i);
        fflush(stdin);
        lend(M, b, i);
        break;
    case 2:
        printf("请输入借阅书籍书名:");
        gets(b);
        fflush(stdin);
        printf("请输入借阅数量:");
        scanf("%d", &i);
        fflush(stdin);
        lend1(M, b, i);
        break;
    // case 3:  printf("请输入借阅书籍作者:");
    //         gets(b);
    //         fflush(stdin);
    //         printf("请输入借阅数量:");
    //         scanf("%d",&i);
    //         fflush(stdin);
    //         lend2(M,b,i);
    //         break;
    default:
        system("cls");
        printf("不存在此操作，请重新选择！！！\n");
        goto L0;
    }
}
void switchr(LinkList &M)
{
L1:
    printf("还书方式\n"
           "1.书名\n"
           "2.书号\n"
           "3.作者\n");
    int x, i;
    char b[MAXSIZE];
    printf("请选择还书方式:");
    scanf("%d", &x);
    fflush(stdin);
    switch (x)
    {
    case 1:
        printf("请输入归还书籍书号:");
        gets(b);
        fflush(stdin);
        printf("请输入归还数量:");
        scanf("%d", &i);
        fflush(stdin);
        returnb(M, b, i);
        break;
    case 2:
        printf("请输入归还书籍书名:");
        gets(b);
        fflush(stdin);
        printf("请输入归还数量:");
        scanf("%d", &i);
        fflush(stdin);
        returnb1(M, b, i);
        break;
    // case 3:  printf("请输入归还书籍作者:");
    //         gets(b);
    //         fflush(stdin);
    //         printf("请输入归还数量:");
    //         scanf("%d",&i);
    //         fflush(stdin);
    //         returnb2(M,b,i);
    //         break;
    default:
        system("cls");
        printf("不存在此操作，请重新选择！！！\n");
        goto L1;
    }
}

void getpwd(char *pwd, int pwdlen) //密码转星号
{
    char ch = 0;
    int i = 0;
    while (i < pwdlen)
    {
        ch = getch();
        if (ch == '\r')
        {
            printf("\n");
            break;
        }

        if (ch == '\b' && i > 0)
        {
            i--;
            printf("\b \b");
        }
        else if (isprint(ch))
        {
            pwd[i] = ch;
            printf("*");
            i++;
        }
    }
    pwd[i] = 0;
}
int main()
{
    int a;
    LinkList Ctr;
    init(Ctr);
    while (1)
    {
        printf("\t\t欢迎来到海南大学图书管理系统\n");
        printf("\t\t1.采编入库\n"
               "\t\t2.借阅\n"
               "\t\t3.归还\n"
               "\t\t4.查看书籍\n"
               "\t\t按Ctrl+C结束运行\n");
        printf("\t\t请选择你的操作:");
        scanf("%d", &a);
        fflush(stdin);
        switch (a)
        {
        case 1:
            in(Ctr);
            break;
        case 2:
            if (Ctr->next->next == NULL)
            {
                printf("图书馆还未采购书籍，请等待几天再尝试\n");
                break;
            }
            else
            {
                switchl(Ctr);
                break;
            }
        case 3:
            if (Ctr->next->next == NULL)
            {
                printf("图书馆还未采购书籍，请等待几天再尝试\n");
                break;
            }
            else
            {
                switchr(Ctr);
                break;
            }
        case 4:
            if (Ctr->next->next == NULL)
            {
                printf("图书馆还未采购书籍，请等待几天再尝试\n");
                break;
            }
            else
            {
                show(Ctr);
                break;
            }
        default:
            system("cls");
            printf("不存在此操作，请重新选择！！！\n");
            break;
        }
    }
}

void login()
{
    char tell[MAXSIZE], pas[MAXSIZE];
    int r = 0;
    printf("\t\t欢迎来到海南大学图书管理系统\n");
    printf("请输入你的学号:");
    gets(tell);
    fflush(stdin);
    while (!strcmp(inf[r].id, tell))
        r++;
    printf("请输入你的密码:");
    getpwd(pas, MAXSIZE + 1)
        fflush(stdin);
    if (strcmp(inf[r].passwd, pas))
        printf("密码错误");
    else
    {
    }
}