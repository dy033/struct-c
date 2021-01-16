#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#define MAXSIZE 100
struct INF
{
    int tes;
    char name[MAXSIZE];
    char id[MAXSIZE];
    char passwd[MAXSIZE];
    char booknum[MAXSIZE][MAXSIZE];
    int bookn; //��¼����������
    int booknu[MAXSIZE];
    int y[MAXSIZE];
    int m[MAXSIZE];
    int d[MAXSIZE];
};
typedef struct Node
{
    char num[MAXSIZE];
    char name[MAXSIZE];
    char author[MAXSIZE];
    int bookflag;
    int now;
    int all;

    struct Node *next;
} Node, *LinkList;
int logout = 0;
int fl = 0;
int main();
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
void color(short x) //�ı�������ɫ
{
    if (x >= 0 && x <= 15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
int init(LinkList &L)
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
int in(LinkList &L)
{
    LinkList s, pre;
    pre = L;
    int c3;
    int flag = 1;
    while (flag)
    {
        s = (LinkList)malloc(sizeof(Node));
        fflush(stdin);
        printf("�������鼮���:");
        scanf("%s", &s->num);
        fflush(stdin);
        fl++;
        s->bookflag = fl;
        while (pre->next != NULL && strcmp(pre->num, s->num))
        {
            pre = pre->next;
        }
        if (!strcmp(pre->num, s->num))
        {
            printf("�Ѵ��ڴ��飬��ֱ����������:");
            scanf("%d", &s->now);
            fflush(stdin);
            pre->now += s->now;
            pre->all = pre->now;
            printf("�Ƿ����¼���鼮��������¼���鼮��س����������������ַ��س���");
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
        printf("�������鼮����:");
        scanf("%s", &s->name);
        fflush(stdin);
        printf("�������鼮����:");
        scanf("%s", &s->author);
        fflush(stdin);
        printf("����������:");
        scanf("%d", &s->now);
        fflush(stdin);
        printf("�Ƿ����¼���鼮��������¼���鼮��س����������������ַ��س���");

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
    printf("���еĵ��鼮��Ϣ����:\n");
    printf("���\t����\t����\tʣ����\t�����\n");
    while (pre->next != NULL)
    {
        pre = pre->next;
        printf(" %s\t %s\t %s\t  %d\t  %d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        k++;
    }
    if (k == 0)
    {
        printf("ͼ�����û���飬��ɱ��鼮���\n");
    }
    return 1;
}
int lend(LinkList &L, char nu[MAXSIZE], int i, int r4) //ͨ����Ž����鼮
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
        printf("�����ڴ���!\n");
        color(16);
        return 0;
    }
    if (pre->now == 0)
    {
        printf("���\t����\t����\tʣ����\t�����\n");
        printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("�����ѱ����꣡\n");
        color(16);
        return 0;
    }
    if (pre->now < i)
    {
        printf("���\t����\t����\tʣ����\t�����\n");
        printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("�����治��%d����\n", i);
        color(16);
        return 0;
    }
    pre->now -= i;
    printf("���ĵ��鼮��Ϣ����:\n");
    printf("���\t����\t����\t��������\tʣ����\t�黹ʱ��\n");
    printf(" %s\t %s\t %s\t  %d\t\t%d\t%d��%d��%d��\n", pre->num, pre->name, pre->author, i, pre->now, 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("�ɹ��������!\n");
    inf[r4].bookn = pre->bookflag;
    inf[r4].y[inf[r4].bookn] = 1900 + p->tm_year;
    inf[r4].m[inf[r4].bookn] = 1 + p->tm_mon;
    inf[r4].d[inf[r4].bookn] = p->tm_mday;
    strcpy(inf[r4].booknum[inf[r4].bookn], pre->num);
    inf[r4].booknu[inf[r4].bookn] += i;
    return 1;
}
int lend1(LinkList &L, char nam[MAXSIZE], int i, int r4) //ͨ����������鼮
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
        printf("�����ڴ���!\n");
        color(16);
        return 0;
    }
    if (pre->now == 0)
    {
        printf("���\t����\t����\tʣ����\t�����\n");
        printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("�����ѱ����꣡\n");
        color(16);
        return 0;
    }
    if (pre->now < i)
    {
        printf("���\t����\t����\tʣ����\t�����\n");
        printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("�����治��%d����\n", i);
        color(16);
        return 0;
    }
    pre->now -= i;
    printf("���ĵ��鼮��Ϣ����:\n");
    printf("���\t����\t����\t��������\tʣ����\t�黹ʱ��\n");
    printf(" %s\t %s\t %s\t  %d\t\t%d\t%d��%d��%d��\n", pre->num, pre->name, pre->author, i, pre->now, 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("�ɹ��������!\n");
    inf[r4].bookn = pre->bookflag;
    inf[r4].y[inf[r4].bookn] = 1900 + p->tm_year;
    inf[r4].m[inf[r4].bookn] = 1 + p->tm_mon;
    inf[r4].d[inf[r4].bookn] = p->tm_mday;
    strcpy(inf[r4].booknum[inf[r4].bookn], pre->num);
    inf[r4].booknu[inf[r4].bookn] += i;
    return 1;
}
// int lend2(LinkList L,char aut[MAXSIZE],int i) //ͨ�����߽���鼮
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
//           printf("�����ڴ���!");
//             return 0;
//         }
//         if(g==1)
//         {
//             printf("���\t���\t����\t����\tʣ����\t�����\n");
//         }
//         if(pre->now==0)
//          {
//             g--;
//         }
//         printf("%d\t%s\t%s\t%s\t%d\t%d\n",g,pre->num,pre->name,pre->author,pre->now,pre->all);
//         pre=pre->next;
//     }
//     g=0;
// 	printf("��ѡ����Ҫ���ĵ��鼮:");
//     scanf("%d",&b);
//     while(g<a[b-1])
//         {
//             pre2=pre2->next;
//             g++;
//         }
// 	pre2->now-=i;
// 	printf("���ĵ��鼮��Ϣ����:\n");
//     printf("���\t����\t����\t��������\tʣ����\n");
//     printf("%s\t%s\t%s\t%d\t%d\n",pre2->num,pre2->name,pre2->author,i,pre2->now);
// 	printf("�ɹ��������!");
// 	return 1;

// }

int returnb(LinkList &L, char nu[MAXSIZE], int i, int r4) //ͨ����Ź黹�鼮
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
        printf("�����ڴ���!\n");
        color(16);
        return 0;
    }
    if (pre->all < i + pre->now)
    {
        printf("���\t����\t����\tʣ����\t�����\n");
        printf("%s\t%s\t%s\t", pre->num, pre->name, pre->author);
        color(4);
        printf("%d\t", pre->now + i);
        color(16);
        printf("%d\n", pre->all);
        color(4);
        printf("�黹����������Ӧ�п�����������Ƿ�ȷ������\n");
        color(16);
        return 0;
    }
    pre->now += i;
    printf("�黹���鼮��Ϣ����:\n");
    printf("���\t����\t����\t�黹����\tʣ����\n");
    printf(" %s\t %s\t %s\t  %d\t\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("�ɹ��黹����!\n");
    inf[r4].bookn = pre->bookflag;
    strcpy(inf[r4].booknum[inf[r4].bookn], "");
    inf[r4].booknu[inf[r4].bookn] -= i;
    inf[r4].bookn--;
    return 1;
}
int returnb1(LinkList &L, char nam[MAXSIZE], int i, int r4) //ͨ�������黹�鼮
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
        printf("�����ڴ���!\n");
        color(16);
        return 0;
    }
    if (pre->all < i + pre->now)
    {
        printf("���\t����\t����\tʣ����\t�����\n");
        printf("%s\t%s\t%s\t", pre->num, pre->name, pre->author);
        color(4);
        printf("%d\t", pre->now + i);
        color(16);
        printf("%d\n", pre->all);
        color(4);
        printf("�黹����������Ӧ�п�����������Ƿ�ȷ������\n");
        color(16);
        return 0;
    }
    pre->now += i;
    printf("�黹���鼮��Ϣ����:\n");
    printf("���\t����\t����\t�黹����\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("�ɹ��黹����!\n");
    inf[r4].bookn = pre->bookflag;
    strcpy(inf[r4].booknum[inf[r4].bookn], "");
    inf[r4].booknu[inf[r4].bookn] -= i;
    inf[r4].bookn--;
    return 1;
}
// int returnb2(LinkList &L,char aut[MAXSIZE],int i) //ͨ�����߹黹�鼮
// {
//     LinkList pre,pre2;
// 	int k,b,g;
// 	pre=L;
//     pre2=L;
// 	k=0;
//     g=0;
//     int a[MAXSIZE];
//     printf("���\t���\t����\t����\tʣ����\t�����\n");
//     while(pre->next!=NULL)
//     {
//         while(pre->next!=NULL&&strcmp(pre->author,aut))
//         {
//             pre=pre->next;
//             k++;
//         }
//         if(!(pre->next))
//         {
//             printf("�����ڴ���!");
//             return 0;
//         }

//         a[i]=k;
//         g++;
//         printf("%d\t%s\t%s\t%s\t%d\t%d\n",k,pre->num,pre->name,pre->author,pre->now,pre->all);
//     }
//     g=0;
// 	printf("��������Ҫ�黹���鼮��");
//     scanf("%d",&b);
//     while(g<a[b])
//         {
//             pre2=pre2->next;
//             g++;
//         }

// 	pre2->now+=i;
// 	printf("�黹���鼮��Ϣ����:\n");
//     printf("���\t����\t����\t�黹����\tʣ����\n");
//     printf("%s\t%s\t%s\t%d\t%d\n",pre->num,pre->name,pre->author,i,pre->now);
// 	printf("�ɹ��黹����!");
// 	return 1;
// }
int own(LinkList &L, int r3)
{
    LinkList pre;
    int k;
    pre = L;
    k = 0;
    while (pre != NULL)
    {
        inf[r3].bookn = pre->bookflag;
        while (pre->next != NULL && strcmp(pre->num, inf[r3].booknum[inf[r3].bookn]))
        {
            pre = pre->next;
            inf[r3].bookn = pre->bookflag;
            ++k;
        }

        if (!(pre))
        {
            printf("�㻹û�н��飡");
            return 0;
        }
        if (k == 1)
        {
            printf("���\t���\t����\t����\t��������\tͼ���ʣ����\t�黹����\n");
        }
        if (!strcmp(pre->num, inf[r3].booknum[inf[r3].bookn]))
        {
            printf(" %d\t %s\t %s\t %s\t  %d\t\t       %d\t\t%d��%d��%d��\n", k, pre->num, pre->name, pre->author, inf[r3].booknu[inf[r3].bookn], pre->now, inf[r3].y[inf[r3].bookn], inf[r3].m[inf[r3].bookn], inf[r3].d[inf[r3].bookn]);
        }

        pre = pre->next;
    }
    return 1;
}
void switchl(LinkList &M, int r3)
{
    int flag = 0;
    do
    {
        printf("���ķ�ʽ\n"
               "1.���\n"
               "2.����\n");
        int x, i, ii = 0;
        char b[MAXSIZE];
        printf("��ѡ����ķ�ʽ:");
        scanf("%d", &x);
        fflush(stdin);
        switch (x)
        {
        case 1:
            printf("����������鼮���:");
            gets(b);
            fflush(stdin);
            do
            {
                printf("�������������:");
                scanf("%d", &i);
                fflush(stdin);
                if (i > 2)
                {
                    printf("һ�������ֻ�ܽ�2������");
                    ii = 1;
                }
                else
                    ii = 0;
            } while (ii);
            lend(M, b, i, r3);
            flag = 0;
            break;
        case 2:
            printf("����������鼮����:");
            gets(b);
            fflush(stdin);
            do
            {
                printf("�������������:");
                scanf("%d", &i);
                fflush(stdin);
                if (i > 2)
                {
                    printf("һ�������ֻ�ܽ�2������");
                    ii = 1;
                }
                else
                    ii = 0;
            } while (ii);
            lend1(M, b, i, r3);
            flag = 0;
            break;
        // case 3:  printf("����������鼮����:");
        //         gets(b);
        //         fflush(stdin);
        //         printf("�������������:");
        //         scanf("%d",&i);
        //         fflush(stdin);
        //         lend2(M,b,i);
        //         break;
        default:
            system("cls");
            color(4);
            printf("�����ڴ˲�����������ѡ�񣡣���\n");
            color(16);
            flag = 1;
            break;
        }
    } while (flag);
}
void switchr(LinkList &M, int r3)
{
    int flag = 0;
    do
    {
        printf("���鷽ʽ\n"
               "1.���\n"
               "2.����\n");
        int x, i;
        char b[MAXSIZE];
        printf("��ѡ���鷽ʽ:");
        scanf("%d", &x);
        fflush(stdin);
        switch (x)
        {
        case 1:
            printf("������黹�鼮���:");
            gets(b);
            fflush(stdin);
            printf("������黹����:");
            scanf("%d", &i);
            fflush(stdin);
            returnb(M, b, i, r3);
            flag = 0;
            break;
        case 2:
            printf("������黹�鼮����:");
            gets(b);
            fflush(stdin);
            printf("������黹����:");
            scanf("%d", &i);
            fflush(stdin);
            returnb1(M, b, i, r3);
            flag = 0;
            break;
        // case 3:  printf("������黹�鼮����:");
        //         gets(b);
        //         fflush(stdin);
        //         printf("������黹����:");
        //         scanf("%d",&i);
        //         fflush(stdin);
        //         returnb2(M,b,i);
        //         break;
        default:
            system("cls");
            color(4);
            printf("�����ڴ˲�����������ѡ�񣡣���\n");
            color(16);
            flag = 1;
            break;
        }
    } while (flag);
}

int login(int r2)
{
    int a;
    LinkList Ctr;
    if (logout == 1)
        init(Ctr);
    logout = 0;
    while (1)
    {
        if (r2 == 0)
        {
            printf("\t\t\t\t\t%s,��ӭ�������ϴ�ѧͼ�����ϵͳ\n", inf[r2].name);
            printf("\t\t\t\t\t\t1.�ɱ����\n"
                   "\t\t\t\t\t\t2.����\n"
                   "\t\t\t\t\t\t3.�黹\n"
                   "\t\t\t\t\t\t4.�鿴ͼ����鼮\n"
                   "\t\t\t\t\t\t5.�鿴�ѽ����鼮\n"
                   "\t\t\t\t\t\t6.ע��\n"
                   "\t\t\t\t\t��Ctrl+C��������\n");
            printf("\t\t\t\t\t��ѡ����Ĳ���:");
            scanf("%d", &a);
            fflush(stdin);
            switch (a)
            {
            case 1:
                in(Ctr);
                break;
            case 2:
                if (Ctr->next == NULL)
                {
                    printf("ͼ��ݻ�δ�ɹ��鼮����ɹ�\n");
                    break;
                }
                else
                {
                    switchl(Ctr, r2);
                    break;
                }
            case 3:
                if (Ctr->next == NULL)
                {
                    color(4);
                    printf("ͼ��ݻ�δ�ɹ��鼮����ɹ���\n");
                    color(16);
                    break;
                }
                else
                {
                    switchr(Ctr, r2);
                    break;
                }
            case 4:
                if (Ctr->next == NULL)
                {
                    color(4);
                    printf("ͼ��ݻ�δ�ɹ��鼮����ɹ���\n");
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
                main();
                logout = 1;
                break;
            default:
                system("cls");
                color(4);
                printf("�����ڴ˲�����������ѡ�񣡣���\n");
                color(16);
                break;
            }
        }
        else
        {
            printf("\t\t\t\t\t%s,��ӭ�������ϴ�ѧͼ�����ϵͳ\n", inf[r2].name);
            printf("\t\t\t\t\t\t1.����\n"
                   "\t\t\t\t\t\t2.�黹\n"
                   "\t\t\t\t\t\t3.�鿴�鼮\n"
                   "\t\t\t\t\t\t4.�鿴�ѽ����鼮\n"
                   "\t\t\t\t\t\t5.ע��\n"
                   "\t\t\t\t\t��Ctrl+C��������\n");
            printf("\t\t\t\t\t��ѡ����Ĳ���:");
            scanf("%d", &a);
            fflush(stdin);
            switch (a)
            {
            case 1:
                if (Ctr->next == NULL)
                {
                    color(4);
                    printf("ͼ��ݻ�δ�ɹ��鼮����ȴ��������ԣ�\n");
                    color(16);
                    break;
                }
                else
                {
                    switchl(Ctr, r2);
                    break;
                }
            case 2:
                if (Ctr->next == NULL)
                {
                    color(4);
                    printf("ͼ��ݻ�δ�ɹ��鼮����ȴ������ٳ��ԣ�\n");
                    color(16);
                    break;
                }
                else
                {
                    switchr(Ctr, r2);
                    break;
                }
            case 3:
                if (Ctr->next == NULL)
                {
                    color(4);
                    printf("ͼ��ݻ�δ�ɹ��鼮����ȴ������ٳ��ԣ�\n");
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
                main();
                break;
            default:
                system("cls");
                color(4);
                printf("�����ڴ˲�����������ѡ�񣡣���\n");
                color(16);
                break;
            }
        }
    }
}
void initinf() //���5���û�
{
    strcpy(inf[0].id, "1"); //����Ϊ��������Ա����������鼮
    strcpy(inf[0].name, "����");
    strcpy(inf[0].passwd, "1");
    strcpy(inf[1].id, "2");
    strcpy(inf[1].name, "����");
    strcpy(inf[1].passwd, "2");
    strcpy(inf[2].id, "3");
    strcpy(inf[2].name, "����");
    strcpy(inf[2].passwd, "3");
    strcpy(inf[3].id, "4");
    strcpy(inf[3].name, "����");
    strcpy(inf[3].passwd, "4");
    strcpy(inf[4].id, "5");
    strcpy(inf[4].name, "����");
    strcpy(inf[4].passwd, "5");
    inf[0].tes = 1; //�鿴�Ƿ����û�
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
void getpwd(char *pwd, int pwdlen) //����ת�Ǻ�
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
    int f0 = 0;
    do
    {
        char tell[MAXSIZE], pas[MAXSIZE];
        int r = 0, r1;
        int f = 0, ff = 0; //ѭ����־
        inf[0].tes = 0;
        initinf();
        printf("\t\t\t\t\t\t��ӭ�������ϴ�ѧͼ�����ϵͳ\n");
        do
        {
            printf("\t\t����������˺�:");
            scanf("%s", tell);
            fflush(stdin);
            if (inf[0].tes == 0)
            {
                color(4);
                printf("û��¼��ѧ����\n");
                color(16);
                f0 = 1;
            }
            if (!strcmp(tell, "\r"))
                f = 1;
            while (strcmp(inf[r].id, tell) && strcmp(tell, "\r"))
            {

                if (r >= MAXSIZE)
                {
                    color(4);
                    printf("�����ڴ��û�����\n");
                    color(16);
                    f = 1;
                    break;
                }
                else
                {
                    f = 0;
                }
                r++;
            }
            r1 = r;
            if (!strcmp(inf[r].id, tell))
                f = 0;
            r = 0;
        } while (f);
        if (f0 == 1)
            break;
        do
        {
            printf("\t\t�������������:");
            getpwd(pas, MAXSIZE + 1);
            fflush(stdin);
            if (strcmp(inf[r1].passwd, pas))
            {
                color(4);
                printf("�������,���������룡\n");
                color(16);
                ff = 1;
            }
            else
            {
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); //ʹ��system("cls")����bug�������ֶ�����
                ff = 0;
                login(r1);
            }
        } while (ff);

    } while (f0);
}