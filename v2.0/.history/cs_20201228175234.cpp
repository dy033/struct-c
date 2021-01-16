#include <stdio.h>
#include <stdlib.h>  //清屏函数需要的头文件
#include <string.h>  //字符复制,比较,连接函数需要的头文件
#include <time.h>    //获取时间的函数需要的头文件
#include <conio.h>   //输入不实时打印函数需要的头文件
#include <ctype.h>   //判断是否能打印函数需要的头文件
#include <windows.h> //改变字体颜色需要的头文件

#define MAXSIZE 100

struct INF //用户基本信息结构体
{
    int tes;
    char name[MAXSIZE];
    char id[MAXSIZE];
    char passwd[MAXSIZE];
    char booknum[MAXSIZE][MAXSIZE]; //记录书号
    int bookn;                      //变量,用来存储书的标记号
    int booknu[MAXSIZE];            //记入每种书借了多少本
    int y[MAXSIZE];
    int m[MAXSIZE];
    int d[MAXSIZE];
};
typedef struct Node //存储书籍基本信息的结构体
{
    char num[MAXSIZE];
    char name[MAXSIZE];
    char author[MAXSIZE];
    int bookflag;
    int now;
    int all;

    struct Node *next;
} Node, *LinkList;

INF inf[MAXSIZE];
int logout = 0;
int fl = 0;

int main();
int login(int); //登录系统

int init(LinkList &); //书籍信息初始化
void initinf();       //添加5个用户 管理员账户为1，密码为1；普通账户2，3，4，5，密码分别为2，3，4，5。

int in(LinkList &); //录入书籍信息

void switchl(LinkList &, int);           //选择借阅书籍方式
int lend(LinkList &, char *, int, int);  //通过书号借阅书籍
int lend1(LinkList &, char *, int, int); //通过书名借出书籍

void switchr(LinkList &, int);              //选择归还书籍方式
int returnb(LinkList &, char *, int, int);  //通过书号归还书籍
int returnb1(LinkList &, char *, int, int); //通过书名归还书籍

int show(LinkList &);     //显示图书馆中所有书籍
int own(LinkList &, int); //查看自己借的书籍以及归还时间

int bookdataw(LinkList &);      //存储图书馆中所有书籍数据
int bookdatar(LinkList &);      //读取存储图书馆中所有书籍的数据
int userdataw(LinkList &, int); //存储用户借阅所有书籍数据
int userdatar(int);             //读取用户借阅所有书籍数据

void color(short);        //改变字体颜色
void getpwd(char *, int); //密码转星号

int main()
{
    int flag0 = 0;
    printf("\t\t\t\t\t\t欢迎来到海南大学图书管理系统\n");
    do
    {
        char tell[MAXSIZE], pas[MAXSIZE];
        int r = 0, r1, r2 = 0;
        int flag1 = 0, flag2 = 0; //循环标志
        inf[0].tes = 0;
        initinf();
        do
        {
            printf("\t\t请输入你的账号:");
            scanf("%s", tell);
            fflush(stdin);
            if (inf[0].tes == 0)
            {
                color(4);
                printf("没有录入学生！\n");
                color(16);
                flag0 = 1;
            }
            if (!strcmp(tell, "\r"))
                flag1 = 1;
            while (strcmp(inf[r].id, tell) && strcmp(tell, "\r"))
            {

                if (r >= MAXSIZE)
                {
                    color(4);
                    printf("不存在此用户！！\n");
                    color(16);
                    flag1 = 1;
                    break;
                }
                else
                {
                    flag1 = 0;
                    flag0 = 0;
                }
                r++;
            }
            r1 = r;
            if (!strcmp(inf[r].id, tell))
            {
                flag0 = 0;
                flag1 = 0;
            }
            r = 0;
        } while (flag1);
        if (flag0 == 1)
            break;
        do //用户输入密码
        {
            printf("\t\t请输入你的密码:");
            r2++;
            getpwd(pas, MAXSIZE + 1);
            fflush(stdin);
            if (r2 > 2)
            {
                system("cls");
                color(4);
                printf("密码输入错误超过3次，请检查你的账号是否正确！！\n");
                color(16);
                flag0 = 1;
                break;
            }
            if (strcmp(inf[r1].passwd, pas))
            {
                color(4);
                printf("密码错误,请重新输入！\n");
                color(16);
                flag2 = 1;
            }
            else //账户密码正确,登录系统
            {
                printf("\n\n\n\n\n\n");
                system("cls"); //使用system("cls")出现bug，启用手动清屏
                flag2 = 0;
                flag0 = 0;
                login(r1);
            }

        } while (flag2);

    } while (flag0);
}
int login(int r2) //登录系统
{
    int a;
    LinkList Ctr;
    bookdatar(Ctr);
    userdatar(r2);
    if (logout == 1)
        init(Ctr);
    logout = 0;
    while (1)
    {
        if (r2 == 0)
        {
            printf("\t\t\t\t\t%s,欢迎来到海南大学图书管理系统\n", inf[r2].name);
            printf("\t\t\t\t\t\t1.采编入库\n"
                   "\t\t\t\t\t\t2.借阅\n"
                   "\t\t\t\t\t\t3.归还\n"
                   "\t\t\t\t\t\t4.查看图书馆书籍\n"
                   "\t\t\t\t\t\t5.查看已借阅书籍\n"
                   "\t\t\t\t\t\t6.注销\n"
                   "\t\t\t\t\t     按Ctrl+C结束运行\n");
            printf("\t\t\t\t\t请选择你的操作:");
            scanf("%d", &a);
            fflush(stdin);
            switch (a)
            {
            case 1:
                in(Ctr);
                bookdataw(Ctr);
                break;
            case 2:
                if (Ctr->next == NULL)
                {
                    color(4);
                    printf("\t\t\t图书馆还未采购书籍，请采购\n");
                    color(16);
                    break;
                }
                else
                {
                    switchl(Ctr, r2);
                    userdataw(Ctr, r2);
                    bookdataw(Ctr);
                    break;
                }
            case 3:
                if (Ctr->next == NULL)
                {
                    color(4);
                    printf("\t\t\t\t\t\t图书馆还未采购书籍，请采购！\n");
                    color(16);
                    break;
                }
                else
                {
                    switchr(Ctr, r2);
                    userdataw(Ctr, r2);
                    bookdataw(Ctr);
                    break;
                }
            case 4:
                if (Ctr->next == NULL)
                {
                    color(4);
                    printf("\t\t\t\t\t\t图书馆还未采购书籍，请采购！\n");
                    color(16);
                    break;
                }
                else
                {
                    show(Ctr);
                    break;
                }
            case 5:
                own(Ctr, r2);
                break;
            case 6:
                system("cls");
                main();
                logout = 1;
                break;
            default:
                system("cls");
                color(4);
                printf("\t\t\t\t\t\t不存在此操作，请重新选择！！！\n");
                color(16);
                break;
            }
        }
        else
        {
            bookdataw(Ctr);
            printf("\t\t\t\t\t%s,欢迎来到海南大学图书管理系统\n", inf[r2].name);
            printf("\t\t\t\t\t\t1.借阅\n"
                   "\t\t\t\t\t\t2.归还\n"
                   "\t\t\t\t\t\t3.查看书籍\n"
                   "\t\t\t\t\t\t4.查看已借阅书籍\n"
                   "\t\t\t\t\t\t5.注销\n"
                   "\t\t\t\t\t按Ctrl+C结束运行\n");
            printf("\t\t\t\t\t请选择你的操作:");
            scanf("%d", &a);
            fflush(stdin);
            switch (a)
            {
            case 1:
                if (Ctr->next == NULL)
                {
                    color(4);
                    printf("\t\t\t图书馆还未采购书籍，请等待几天再试！\n");
                    color(16);
                    break;
                }
                else
                {
                    switchl(Ctr, r2);
                    userdataw(Ctr, r2);
                    break;
                }
            case 2:
                if (Ctr->next == NULL)
                {
                    color(4);
                    printf("\t\t\t图书馆还未采购书籍，请等待几天再尝试！\n");
                    color(16);
                    break;
                }
                else
                {
                    switchr(Ctr, r2);
                    userdataw(Ctr, r2);
                    break;
                }
            case 3:
                if (Ctr->next == NULL)
                {
                    color(4);
                    printf("\t\t\t图书馆还未采购书籍，请等待几天再尝试！\n");
                    color(16);
                    break;
                }
                else
                {
                    show(Ctr);
                    break;
                }
            case 4:
                own(Ctr, r2);
                break;
            case 5:
                system("cls");
                main();
                break;
            default:
                system("cls");
                color(4);
                printf("\t\t\t不存在此操作，请重新选择！！！\n");
                color(16);
                break;
            }
        }
    }
}
int init(LinkList &L) //书籍信息初始化
{
    LinkList L0;
    L = (LinkList)malloc(sizeof(Node));
    L0 = (LinkList)malloc(sizeof(Node));
    L0->bookflag = 0;
    L->next = NULL;
    L0->next = L->next;
    L->next = L0;
    return 1;
}
void initinf() //添加5个用户
{
    strcpy(inf[0].id, "1"); //张三为超级管理员，可以添加书籍
    strcpy(inf[0].name, "张三");
    strcpy(inf[0].passwd, "1");
    strcpy(inf[1].id, "2");
    strcpy(inf[1].name, "李四");
    strcpy(inf[1].passwd, "2");
    strcpy(inf[2].id, "3");
    strcpy(inf[2].name, "王五");
    strcpy(inf[2].passwd, "3");
    strcpy(inf[3].id, "4");
    strcpy(inf[3].name, "赵六");
    strcpy(inf[3].passwd, "4");
    strcpy(inf[4].id, "5");
    strcpy(inf[4].name, "孙七");
    strcpy(inf[4].passwd, "5");
    inf[0].tes = 1; //查看是否有用户
    inf[0].bookn = 0;
    inf[1].bookn = 0;
    inf[2].bookn = 0;
    inf[3].bookn = 0;
    inf[4].bookn = 0;
    for (int s = 0; s < MAXSIZE; s++)
    {
        inf[0].booknu[s] = 0;
        inf[1].booknu[s] = 0;
        inf[2].booknu[s] = 0;
        inf[3].booknu[s] = 0;
        inf[4].booknu[s] = 0;
    }
}
int in(LinkList &L) //录入书籍信息
{
    system("cls");
    printf("\t\t\t开始录入书籍\n");
    LinkList s, pre;
    int c3;
    int flag = 1;
    while (flag)
    {
        s = (LinkList)malloc(sizeof(Node));
        fflush(stdin);
        printf("\t\t\t请输入书籍书号:");
        scanf("%s", &s->num);
        fflush(stdin);
        fl++;
        s->bookflag = fl;
        pre = L;
        while (pre->next != NULL && strcmp(pre->num, s->num))
        {
            pre = pre->next;
        }
        if (!strcmp(pre->num, s->num))
        {
            printf("\t\t\t已存在此书，请直接输入数量:");
            scanf("%d", &s->now);
            fflush(stdin);
            pre->now += s->now;
            pre->all = pre->now;
            printf("是否继续录入书籍，若继续录入书籍请回车，否则输入任意字符回车：");
            if (getchar() != '\n')
            {
                fflush(stdin);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            continue;
        }
        printf("\t\t\t请输入书籍书名:");
        scanf("%s", &s->name);
        fflush(stdin);
        printf("\t\t\t请输入书籍作者:");
        scanf("%s", &s->author);
        fflush(stdin);
        printf("\t\t\t请输入数量:");
        scanf("%d", &s->now);
        fflush(stdin);
        printf("是否继续录入书籍，若继续录入书籍请回车，否则输入任意字符回车：");
        s->all = s->now;
        s->next = L->next;
        L->next = s;
        if (getchar() != '\n')
        {
            fflush(stdin);
            flag = 0;
        }
    }
    system("cls");
    return 1;
}
void switchl(LinkList &M, int r3) //选择借阅书籍方式
{
    system("cls");
    int flag = 0;
    do
    {
        printf("\n\t\t\t\t\t\t借阅方式\n"
               "\t\t\t\t\t\t 1.书号\n"
               "\t\t\t\t\t\t 2.书名\n");
        int x, i;
        char b[MAXSIZE];
        printf("\t\t\t请选择借阅方式:");
        scanf("%d", &x);
        fflush(stdin);
        switch (x)
        {
        case 1:
            printf("\t\t\t请输入借阅书籍书号:");
            gets(b);
            fflush(stdin);
            printf("\t\t\t请输入借阅数量:");
            scanf("%d", &i);
            fflush(stdin);
            lend(M, b, i, r3);
            flag = 0;
            break;
        case 2:
            printf("\t\t\t请输入借阅书籍书名:");
            gets(b);
            fflush(stdin);
            printf("\t\t\t请输入借阅数量:");
            scanf("%d", &i);
            fflush(stdin);
            lend1(M, b, i, r3);
            flag = 0;
            break;
        default:
            system("cls");
            color(4);
            printf("\t\t\t不存在此操作，请重新选择！！！\n\n");
            color(16);
            flag = 1;
            break;
        }
    } while (flag);
}
int lend(LinkList &L, char nu[MAXSIZE], int i, int r4) //通过书号借阅书籍
{
    time_t timep;
    struct tm *p;
    time(&timep);
    timep = time(NULL) + 31 * 24 * 60 * 60;
    p = gmtime(&timep);
    LinkList pre;
    int k;
    pre = L;
    k = 0;
    while (pre->next != NULL && strcmp(pre->num, nu))
    {
        pre = pre->next;
    }
    if (strcmp(pre->num, nu))
    {
        color(4);
        printf("不存在此书!\n\n");
        color(16);
        return 0;
    }
    if (pre->now == 0)
    {
        system("cls");
        printf("\t\t\t书号\t书名\t作者\t剩余量\t库存量\n");
        printf("\t\t\t%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("\t\t\t此书已被借完！\n\n");
        color(16);
        return 0;
    }
    if (pre->now < i)
    {
        system("cls");
        printf("\t\t\t书号\t书名\t作者\t剩余量\t库存量\n");
        printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("\t\t\t此书库存不足%d本！\n\n", i);
        color(16);
        return 0;
    }
    inf[r4].bookn = pre->bookflag;
    if (inf[r4].booknu[inf[r4].bookn] + i > 2)
    {
        printf("你以前关于本书的借阅信息如下\n");
        printf("\t\t\t书号\t书名\t作者\t借阅量\n");
        printf("\t\t\t%s\t%s\t%s\t", pre->num, pre->name, pre->author);
        color(4);
        printf("%d\t", inf[r4].booknu[inf[r4].bookn]);
        color(16);
        color(4);
        printf("\t\t\t一本书最多只能借2本！！\n");
        color(16);
        return 0;
    }
    pre->now -= i;
    system("cls");
    printf("\t\t\t借阅的书籍信息如下:\n");
    printf("\t\t\t书号\t书名\t作者\t借阅数量\t剩余量\t归还时间\n");
    printf("\t\t\t %s\t %s\t %s\t  %d\t\t%d\t%d年%d月%d日\n", pre->num, pre->name, pre->author, i, pre->now, 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("\t\t\t成功借出此书!\n\n");
    inf[r4].bookn = pre->bookflag;
    inf[r4].y[inf[r4].bookn] = 1900 + p->tm_year;
    inf[r4].m[inf[r4].bookn] = 1 + p->tm_mon;
    inf[r4].d[inf[r4].bookn] = p->tm_mday;
    strcpy(inf[r4].booknum[inf[r4].bookn], pre->num);
    inf[r4].booknu[inf[r4].bookn] += i;
    return 1;
}
int lend1(LinkList &L, char nam[MAXSIZE], int i, int r4) //通过书名借出书籍
{
    time_t timep;
    struct tm *p;
    time(&timep);
    timep = time(NULL) + 31 * 24 * 60 * 60;
    p = gmtime(&timep);
    LinkList pre;
    int k;
    pre = L;
    k = 0;
    while (pre->next != NULL && strcmp(pre->name, nam))
    {
        pre = pre->next;
    }
    if (strcmp(pre->num, nam))
    {
        color(4);
        printf("\t\t\t不存在此书!\n\n");
        color(16);
        return 0;
    }
    if (pre->now == 0)
    {
        printf("\t\t\t书号\t书名\t作者\t剩余量\t库存量\n");
        printf("\t\t\t%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("\t\t\t此书已被借完！\n\n");
        color(16);
        return 0;
    }
    if (pre->now < i)
    {
        printf("\t\t\t书号\t书名\t作者\t剩余量\t库存量\n");
        printf("\t\t\t%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("\t\t\t此书库存不足%d本！\n\n", i);
        color(16);
        return 0;
    }
    inf[r4].bookn = pre->bookflag;
    if (inf[r4].booknu[inf[r4].bookn] + i > 2)
    {
        printf("你以前关于本书的借阅信息如下\n");
        printf("\t\t\t书号\t书名\t作者\t借阅量\n");
        printf("\t\t\t%s\t%s\t%s\t", pre->num, pre->name, pre->author);
        color(4);
        printf("%d\t", inf[r4].booknu[inf[r4].bookn]);
        color(16);
        color(4);
        printf("\t\t\t一本书最多只能借2本！！\n");
        color(16);
        return 0;
    }
    pre->now -= i;
    system("cls");
    printf("\t\t\t借阅的书籍信息如下:\n");
    printf("\t\t\t书号\t书名\t作者\t借阅数量\t剩余量\t归还时间\n");
    printf("\t\t\t %s\t %s\t %s\t  %d\t\t%d\t%d年%d月%d日\n", pre->num, pre->name, pre->author, i, pre->now, 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("\t\t\t成功借出此书!\n\n");
    inf[r4].bookn = pre->bookflag;
    inf[r4].y[inf[r4].bookn] = 1900 + p->tm_year;
    inf[r4].m[inf[r4].bookn] = 1 + p->tm_mon;
    inf[r4].d[inf[r4].bookn] = p->tm_mday;
    strcpy(inf[r4].booknum[inf[r4].bookn], pre->num);
    inf[r4].booknu[inf[r4].bookn] += i;
    return 1;
}
void switchr(LinkList &M, int r3) //选择归还书籍方式
{
    int flag = 0;
    system("cls");
    do
    {
        printf("\n\t\t\t\t\t\t还书方式\n"
               "\t\t\t\t\t\t 1.书号\n"
               "\t\t\t\t\t\t 2.书名\n");
        int x, i;
        char b[MAXSIZE];
        printf("\t\t\t请选择还书方式:");
        scanf("%d", &x);
        fflush(stdin);
        switch (x)
        {
        case 1:
            printf("\t\t\t请输入归还书籍书号:");
            gets(b);
            fflush(stdin);
            printf("\t\t\t请输入归还数量:");
            scanf("%d", &i);
            fflush(stdin);
            returnb(M, b, i, r3);
            flag = 0;
            break;
        case 2:
            printf("\t\t\t请输入归还书籍书名:");
            gets(b);
            fflush(stdin);
            printf("\t\t\t请输入归还数量:");
            scanf("%d", &i);
            fflush(stdin);
            returnb1(M, b, i, r3);
            flag = 0;
            break;
        default:
            system("cls");
            color(4);
            printf("\t\t\t不存在此操作，请重新选择！！！\n\n");
            color(16);
            flag = 1;
            break;
        }
    } while (flag);
}

int returnb(LinkList &L, char nu[MAXSIZE], int i, int r4) //通过书号归还书籍
{
    LinkList pre;
    int k;
    pre = L;
    k = 0;

    while (pre->next != NULL && strcmp(pre->num, nu))
    {
        pre = pre->next;
    }
    if (strcmp(pre->num, nu))
    {
        color(4);
        printf("\t\t\t不存在此书!\n\n");
        color(16);
        return 0;
    }
    inf[r4].bookn = pre->bookflag;
    if (inf[r4].booknu[inf[r4].bookn] < i)
    {
        printf("\t\t\t书号\t书名\t作者\t借阅量\t库存量\n");
        printf("\t\t\t%s\t%s\t%s\t", pre->num, pre->name, pre->author);
        color(4);
        printf("%d\t", inf[r4].booknu[inf[r4].bookn]);
        color(16);
        printf("%d\n", pre->all);
        color(4);
        printf("\t\t\t归还的数量超出应有的借阅量，请检查是否确认无误！\n\n");
        color(16);
        return 0;
    }
    pre->now += i;
    system("cls");
    printf("\t\t\t归还的书籍信息如下:\n");
    printf("\t\t\t书号\t书名\t作者\t归还数量\t剩余量\n");
    printf("\t\t\t %s\t %s\t %s\t  %d\t\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("\t\t\t成功归还此书!\n\n");
    inf[r4].bookn = pre->bookflag;
    strcpy(inf[r4].booknum[inf[r4].bookn], "");
    inf[r4].booknu[inf[r4].bookn] -= i;
    return 1;
}
int returnb1(LinkList &L, char nam[MAXSIZE], int i, int r4) //通过书名归还书籍
{
    LinkList pre;
    int k;
    pre = L;
    k = 0;

    while (pre->next != NULL && strcmp(pre->name, nam))
    {
        pre = pre->next;
    }
    if (strcmp(pre->num, nam))
    {
        color(4);
        printf("\t\t\t不存在此书!\n\n");
        color(16);
        return 0;
    }
    if (inf[r4].booknu[inf[r4].bookn] < i)
    {
        printf("\t\t\t书号\t书名\t作者\t借阅量\t库存量\n");
        printf("\t\t\t%s\t%s\t%s\t", pre->num, pre->name, pre->author);
        color(4);
        printf("%d\t", inf[r4].booknu[inf[r4].bookn]);
        color(16);
        printf("%d\n", pre->all);
        color(4);
        printf("\t\t\t归还的数量超出应有的借阅量，请检查是否确认无误！\n\n");
        color(16);
        return 0;
    }
    pre->now += i;
    system("cls");
    printf("\t\t\t归还的书籍信息如下:\n");
    printf("\t\t\t书号\t书名\t作者\t归还数量\t剩余量\n");
    printf("\t\t\t%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("\t\t\t成功归还此书!\n\n");
    inf[r4].bookn = pre->bookflag;
    strcpy(inf[r4].booknum[inf[r4].bookn], "");
    inf[r4].booknu[inf[r4].bookn] -= i;
    return 1;
}
int show(LinkList &L) //显示图书馆中所有书籍
{
    LinkList pre;
    int k = 0;
    pre = L;
    printf("\n\t\t\t\t\t现有的的书籍信息如下:\n");
    printf("\t\t\t\t\t书号\t书名\t作者\t剩余量\t库存量\n");
    while (pre->next != NULL)
    {
        pre = pre->next;
        if (pre->next)
            printf("\t\t\t\t\t %s\t %s\t %s\t  %d\t  %d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        k++;
    }
    if (k == 1)
    {
        color(4);
        printf("\t\t\t图书馆里没有书，请采编书籍入库\n");
        color(16);
    }
    printf("\n");
    return 1;
}
int own(LinkList &L, int r3) //查看自己借的书籍以及归还时间
{
    LinkList pre;
    int k, l = 0, j = 0;
    pre = L;
    k = 0;
    pre = pre->next;
    while (pre != NULL)
    {
        inf[r3].bookn = pre->bookflag;
        while (pre->next != NULL && strcmp(pre->num, inf[r3].booknum[inf[r3].bookn]))
        {
            pre = pre->next;
            inf[r3].bookn = pre->bookflag;
            j++;
        }

        if (pre->next == NULL && j == 0)
        {
            color(4);
            printf("\t\t\t\t\t你还没有借书！\n");
            color(16);
            return 0;
        }
        if (!strcmp(pre->num, inf[r3].booknum[inf[r3].bookn]) && l == 0)
        {
            printf("\n你借阅的书籍信息如下\n");
            printf("\t\t\t序号\t书号\t书名\t作者\t借阅数量\t图书馆剩余量\t归还日期\n\n");
            l++;
        }
        if (!strcmp(pre->num, inf[r3].booknum[inf[r3].bookn]))
        {
            ++k;
            printf("\t\t\t %d\t %s\t %s\t %s\t  %d\t\t       %d\t%d年%d月%d日\n", k, pre->num, pre->name, pre->author, inf[r3].booknu[inf[r3].bookn], pre->now, inf[r3].y[inf[r3].bookn], inf[r3].m[inf[r3].bookn], inf[r3].d[inf[r3].bookn]);
        }

        pre = pre->next;
    }
    printf("\n");
    return 1;
}
int bookdataw(LinkList &L) //存储图书馆中所有书籍数据,数据存储在当前目录下bookdata.txt
{
    LinkList pre;
    int flag3 = 0;
    pre = L;
    remove("bookdata.csv");
    FILE *fp;
    fp = fopen("bookdata.csv", "w");
    while (pre->next->next != NULL)
    {
        if (flag3 != 0)
        {
            fprintf(fp, "\n");
        }
        else
            fprintf(fp, "书标记号,书号,书名,作者,现存量,总量\n");
        pre = pre->next;
        fprintf(fp, "%d,%s,%s,%s,%d,%d", pre->bookflag, pre->num, pre->name, pre->author, pre->now, pre->all);
        flag3++;
    }
    fclose(fp);
    return 1;
}
int bookdatar(LinkList &L) //读取存储图书馆中所有书籍的数据
{
    int i = 0;
    LinkList s, pre;
    pre = L;
    init(L);
    FILE *fp;
    char data[1024] = {};
    char *line, *record, *title;
    fp = fopen("bookdata.csv", "r");
    if (fp == NULL)
    {
        return 0;
    }
    rewind(fp);
    while (!feof(fp))
    {
        if (i == 0)
        {
            title = fgets(data, 1024, fp);
            i++;
        }
        else
        {
            s = (LinkList)malloc(sizeof(Node));
            line = fgets(data, 1024, fp);
            record = strtok(data, ",");

            s->bookflag = atoi(record);
            record = strtok(NULL, ",");
            strcpy(s->num, record);
            record = strtok(NULL, ",");
            strcpy(s->name, record);
            record = strtok(NULL, ",");
            strcpy(s->author, record);
            record = strtok(NULL, ",");
            s->now = atoi(record);
            record = strtok(NULL, ",");
            s->all = atoi(record);

            s->next = L->next;
            L->next = s;
        }
    }
    fclose(fp);
    return 1;
}
int userdataw(LinkList &L, int r3) //存储用户借阅书籍数据,数据存储在当前目录下user.txt
{
    LinkList pre;
    pre = L;
    int flag3 = 0;
    FILE *fp;
    char fileName[MAXSIZE];
    char str[MAXSIZE];
    itoa(r3, str, 10);
    strcpy(fileName, "user");
    strcat(fileName, str);
    strcat(fileName, ".csv");
    remove(fileName);
    fp = fopen(fileName, "w");
    pre = pre->next;
    while (pre != NULL)
    {
        inf[r3].bookn = pre->bookflag;
        while (pre->next != NULL && strcmp(pre->num, inf[r3].booknum[inf[r3].bookn]))
        {
            pre = pre->next;
            inf[r3].bookn = pre->bookflag;
        }
        if (!strcmp(pre->num, inf[r3].booknum[inf[r3].bookn]))
        {
            if (flag3 != 0)
            {
                fprintf(fp, "\n");
            }
            else
                fprintf(fp, "书标记号,书号,数量,归还年,归还月,归还日\n");
            fprintf(fp, "%d,%s,%d,%d,%d,%d", inf[r3].bookn, inf[r3].booknum[inf[r3].bookn], inf[r3].booknu[inf[r3].bookn], inf[r3].y[inf[r3].bookn], inf[r3].m[inf[r3].bookn], inf[r3].d[inf[r3].bookn]);
            flag3++;
        }

        pre = pre->next;
    }
    fclose(fp);
    return 1;
}
int userdatar(int r3) //读取用户借阅所有书籍数据
{
    FILE *fp;
    char fileName[MAXSIZE];
    char str[MAXSIZE];
    itoa(r3, str, 10);
    strcpy(fileName, "user");
    strcat(fileName, str);
    strcat(fileName, ".csv");
    fp = fopen(fileName, "r");
    char data[1024] = {};
    char *line, *record, *title;
    int i = 0;
    if (fp == NULL)
    {
        return 0;
    }
    while (!feof(fp))
    {
        if (i == 0)
        {
            title = fgets(data, 1024, fp);
            i++;
        }
        else
        {
            line = fgets(data, 1024, fp);
            if (strcmp(line, "\n"))
            {
                record = strtok(data, ",");
                inf[r3].bookn = atoi(record);
                record = strtok(NULL, ",");
                strcpy(inf[r3].booknum[inf[r3].bookn], record);
                record = strtok(NULL, ",");
                inf[r3].booknu[inf[r3].bookn] = atoi(record);
                record = strtok(NULL, ",");
                inf[r3].y[inf[r3].bookn] = atoi(record);
                record = strtok(NULL, ",");
                inf[r3].m[inf[r3].bookn] = atoi(record);
                record = strtok(NULL, ",");
                inf[r3].d[inf[r3].bookn] = atoi(record);
            }
        }
    }
    fclose(fp);
    return 1;
}
void color(short x) //改变字体颜色
{
    if (x >= 0 && x <= 15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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
