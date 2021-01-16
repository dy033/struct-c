#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
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
    int tes;
    char name[MAXSIZE];
    char id[MAXSIZE];
    char passwd[MAXSIZE];
    char booknum[MAXSIZE];
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
        printf("�������鼮���:");
        scanf("%s", &s->num);
        fflush(stdin);
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
    while (pre->next->next != NULL)
    {
        pre = pre->next;
        printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        k++;
    }
    if (k == 0)
    {
        printf("ͼ�����û���飬��ɱ��鼮���\n");
    }
    return 1;
}
int lend(LinkList &L, char nu[MAXSIZE], int i) //ͨ����Ž����鼮
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
        printf("�����ڴ���!");
        return 0;
    }
    if (pre->now == 0)
    {
        printf("�����ѱ����꣡");
        return 0;
    }
    pre->now -= i;
    printf("���ĵ��鼮��Ϣ����:\n");
    printf("���\t����\t����\t��������\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("�ɹ��������!");
    return 1;
}
int lend1(LinkList &L, char nam[MAXSIZE], int i) //ͨ����������鼮
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
        printf("�����ڴ���!");
        return 0;
    }
    if (pre->now == 0)
    {
        printf("�����ѱ����꣡");
        return 0;
    }
    pre->now -= i;
    printf("���ĵ��鼮��Ϣ����:\n");
    printf("���\t����\t����\t��������\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("�ɹ��������!");
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

int returnb(LinkList &L, char nu[MAXSIZE], int i) //ͨ����Ź黹�鼮
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
        printf("�����ڴ���!");
        return 0;
    }

    pre->now += i;
    printf("�黹���鼮��Ϣ����:\n");
    printf("���\t����\t����\t�黹����\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("�ɹ��黹����!");
    return 1;
}
int returnb1(LinkList &L, char nam[MAXSIZE], int i) //ͨ�������黹�鼮
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
        printf("�����ڴ���!");
        return 0;
    }

    pre->now += i;
    printf("�黹���鼮��Ϣ����:\n");
    printf("���\t����\t����\t�黹����\tʣ����\n");
    printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("�ɹ��黹����!");
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
void switchl(LinkList &M)
{
L0:
    printf("���ķ�ʽ\n"
           "1.���\n"
           "2.����\n"
           "3.����\n");
    int x, i;
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
        printf("�������������:");
        scanf("%d", &i);
        fflush(stdin);
        lend(M, b, i);
        break;
    case 2:
        printf("����������鼮����:");
        gets(b);
        fflush(stdin);
        printf("�������������:");
        scanf("%d", &i);
        fflush(stdin);
        lend1(M, b, i);
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
        printf("�����ڴ˲�����������ѡ�񣡣���\n");
        goto L0;
    }
}
void switchr(LinkList &M)
{
L1:
    printf("���鷽ʽ\n"
           "1.����\n"
           "2.���\n"
           "3.����\n");
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
        returnb(M, b, i);
        break;
    case 2:
        printf("������黹�鼮����:");
        gets(b);
        fflush(stdin);
        printf("������黹����:");
        scanf("%d", &i);
        fflush(stdin);
        returnb1(M, b, i);
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
        printf("�����ڴ˲�����������ѡ�񣡣���\n");
        goto L1;
    }
}

int login(int r2)
{
    int a;
    LinkList Ctr;
    init(Ctr);
    while (1)
    {
        if (r2 == 0)
        {
            printf("\t\t%s,��ӭ�������ϴ�ѧͼ�����ϵͳ\n", inf[r2].name);
            printf("\t\t1.�ɱ����\n"
                   "\t\t2.����\n"
                   "\t\t3.�黹\n"
                   "\t\t4.�鿴�鼮\n"
                   "\t\t��Ctrl+C��������\n");
            printf("\t\t��ѡ����Ĳ���:");
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
                    printf("ͼ��ݻ�δ�ɹ��鼮����ɹ�\n");
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
                    printf("ͼ��ݻ�δ�ɹ��鼮����ɹ���\n");
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
                    printf("ͼ��ݻ�δ�ɹ��鼮����ɹ���\n");
                    break;
                }
                else
                {
                    show(Ctr);
                    break;
                }
            default:
                system("cls");
                printf("�����ڴ˲�����������ѡ�񣡣���\n");
                break;
            }
        }
        else
        {
            printf("\t\t%s,��ӭ�������ϴ�ѧͼ�����ϵͳ\n", inf[r2].name);
            printf("\t\t1.����\n"
                   "\t\t2.�黹\n"
                   "\t\t3.�鿴�鼮\n"
                   "\t\t��Ctrl+C��������\n");
            printf("\t\t��ѡ����Ĳ���:");
            scanf("%d", &a);
            fflush(stdin);
            switch (a)
            {
            case 1:
                if (Ctr->next->next == NULL)
                {
                    printf("ͼ��ݻ�δ�ɹ��鼮����ȴ��������ԣ�\n");
                    break;
                }
                else
                {
                    switchl(Ctr);
                    break;
                }
            case 2:
                if (Ctr->next->next == NULL)
                {
                    printf("ͼ��ݻ�δ�ɹ��鼮����ȴ������ٳ��ԣ�\n");
                    break;
                }
                else
                {
                    switchr(Ctr);
                    break;
                }
            case 3:
                if (Ctr->next->next == NULL)
                {
                    printf("ͼ��ݻ�δ�ɹ��鼮����ȴ������ٳ��ԣ�\n");
                    break;
                }
                else
                {
                    show(Ctr);
                    break;
                }
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
void initinf() //����5��ѧ��
{
    strcpy(inf[0].id, "1"); //����Ϊ��������Ա�����������鼮
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
    inf[0].tes = 1;
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
        printf("\t\t��ӭ�������ϴ�ѧͼ�����ϵͳ\n");
        do
        {
            printf("���������ѧ��:");
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
            printf("�������������:");
            getpwd(pas, MAXSIZE + 1);
            fflush(stdin);
            if (strcmp(inf[r1].passwd, pas))
            {
                color(4);
                printf("�������,���������룡");
                color(16);
                ff = 1;
            }
            else
            {
                ff = 0;
                login(r1);
            }
        } while (ff);

    } while (f0);
}