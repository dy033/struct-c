#include <stdio.h>
#include <stdlib.h>  //����������Ҫ��ͷ�ļ�
#include <string.h>  //�ַ�����,�Ƚ�,���Ӻ�����Ҫ��ͷ�ļ�
#include <time.h>    //��ȡʱ��ĺ�����Ҫ��ͷ�ļ�
#include <conio.h>   //���벻ʵʱ��ӡ������Ҫ��ͷ�ļ�
#include <ctype.h>   //�ж��Ƿ��ܴ�ӡ������Ҫ��ͷ�ļ�
#include <windows.h> //�ı�������ɫ��Ҫ��ͷ�ļ�

#define MAXSIZE 100

struct INF //�û�������Ϣ�ṹ��
{
    int tes;
    char name[MAXSIZE];
    char id[MAXSIZE];
    char passwd[MAXSIZE];
    char booknum[MAXSIZE][MAXSIZE]; //��¼���
    int bookn;                      //����,�����洢��ı�Ǻ�
    int booknu[MAXSIZE];            //����ÿ������˶��ٱ�
    int y[MAXSIZE];
    int m[MAXSIZE];
    int d[MAXSIZE];
};
typedef struct Node //�洢�鼮������Ϣ�Ľṹ��
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
int login(int); //��¼ϵͳ

int init(LinkList &); //�鼮��Ϣ��ʼ��
void initinf();       //���5���û� ����Ա�˻�Ϊ1������Ϊ1����ͨ�˻�2��3��4��5������ֱ�Ϊ2��3��4��5��

int in(LinkList &); //¼���鼮��Ϣ

void switchl(LinkList &, int);           //ѡ������鼮��ʽ
int lend(LinkList &, char *, int, int);  //ͨ����Ž����鼮
int lend1(LinkList &, char *, int, int); //ͨ����������鼮

void switchr(LinkList &, int);              //ѡ��黹�鼮��ʽ
int returnb(LinkList &, char *, int, int);  //ͨ����Ź黹�鼮
int returnb1(LinkList &, char *, int, int); //ͨ�������黹�鼮

int show(LinkList &);     //��ʾͼ����������鼮
int own(LinkList &, int); //�鿴�Լ�����鼮�Լ��黹ʱ��

int bookdataw(LinkList &);      //�洢ͼ����������鼮����
int bookdatar(LinkList &);      //��ȡ�洢ͼ����������鼮������
int userdataw(LinkList &, int); //�洢�û����������鼮����
int userdatar(int);             //��ȡ�û����������鼮����

void color(short);        //�ı�������ɫ
void getpwd(char *, int); //����ת�Ǻ�

int main()
{
    int flag0 = 0;
    printf("\t\t\t\t\t\t��ӭ�������ϴ�ѧͼ�����ϵͳ\n");
    do
    {
        char tell[MAXSIZE], pas[MAXSIZE];
        int r = 0, r1, r2 = 0;
        int flag1 = 0, flag2 = 0; //ѭ����־
        inf[0].tes = 0;
        initinf();
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
                flag0 = 1;
            }
            if (!strcmp(tell, "\r"))
                flag1 = 1;
            while (strcmp(inf[r].id, tell) && strcmp(tell, "\r"))
            {

                if (r >= MAXSIZE)
                {
                    color(4);
                    printf("�����ڴ��û�����\n");
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
        do //�û���������
        {
            printf("\t\t�������������:");
            r2++;
            getpwd(pas, MAXSIZE + 1);
            fflush(stdin);
            if (r2 > 2)
            {
                system("cls");
                color(4);
                printf("����������󳬹�3�Σ���������˺��Ƿ���ȷ����\n");
                color(16);
                flag0 = 1;
                break;
            }
            if (strcmp(inf[r1].passwd, pas))
            {
                color(4);
                printf("�������,���������룡\n");
                color(16);
                flag2 = 1;
            }
            else //�˻�������ȷ,��¼ϵͳ
            {
                system("cls"); //ʹ��system("cls")����bug�������ֶ�����
                flag2 = 0;
                flag0 = 0;
                login(r1);
            }

        } while (flag2);

    } while (flag0);
}
int login(int r2) //��¼ϵͳ
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
            printf("\t\t\t\t\t%s,��ӭ�������ϴ�ѧͼ�����ϵͳ\n", inf[r2].name);
            printf("\t\t\t\t\t\t1.�ɱ����\n"
                   "\t\t\t\t\t\t2.����\n"
                   "\t\t\t\t\t\t3.�黹\n"
                   "\t\t\t\t\t\t4.�鿴ͼ����鼮\n"
                   "\t\t\t\t\t\t5.�鿴�ѽ����鼮\n"
                   "\t\t\t\t\t\t6.ע��\n"
                   "\t\t\t\t\t     ��Ctrl+C��������\n");
            printf("\t\t\t\t\t��ѡ����Ĳ���:");
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
                    printf("\t\t\tͼ��ݻ�δ�ɹ��鼮����ɹ�\n");
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
                    printf("\t\t\t\t\t\tͼ��ݻ�δ�ɹ��鼮����ɹ���\n");
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
                    printf("\t\t\t\t\t\tͼ��ݻ�δ�ɹ��鼮����ɹ���\n");
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
                printf("\t\t\t\t\t\t�����ڴ˲�����������ѡ�񣡣���\n");
                color(16);
                break;
            }
        }
        else
        {
            bookdataw(Ctr);
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
                    printf("\t\t\tͼ��ݻ�δ�ɹ��鼮����ȴ��������ԣ�\n");
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
                    printf("\t\t\tͼ��ݻ�δ�ɹ��鼮����ȴ������ٳ��ԣ�\n");
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
                    printf("\t\t\tͼ��ݻ�δ�ɹ��鼮����ȴ������ٳ��ԣ�\n");
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
                printf("\t\t\t�����ڴ˲�����������ѡ�񣡣���\n");
                color(16);
                break;
            }
        }
    }
}
int init(LinkList &L) //�鼮��Ϣ��ʼ��
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
int in(LinkList &L) //¼���鼮��Ϣ
{
    system("cls");
    printf("\t\t\t��ʼ¼���鼮\n");
    LinkList s, pre;
    int c3;
    int flag = 1;
    while (flag)
    {
        s = (LinkList)malloc(sizeof(Node));
        fflush(stdin);
        printf("\t\t\t�������鼮���:");
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
            printf("\t\t\t�Ѵ��ڴ��飬��ֱ����������:");
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
        printf("\t\t\t�������鼮����:");
        scanf("%s", &s->name);
        fflush(stdin);
        printf("\t\t\t�������鼮����:");
        scanf("%s", &s->author);
        fflush(stdin);
        printf("\t\t\t����������:");
        scanf("%d", &s->now);
        fflush(stdin);
        printf("�Ƿ����¼���鼮��������¼���鼮��س����������������ַ��س���");
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
void switchl(LinkList &M, int r3) //ѡ������鼮��ʽ
{
    system("cls");
    int flag = 0;
    do
    {
        printf("\n\t\t\t\t\t\t���ķ�ʽ\n"
               "\t\t\t\t\t\t 1.���\n"
               "\t\t\t\t\t\t 2.����\n");
        int x, i;
        char b[MAXSIZE];
        printf("\t\t\t��ѡ����ķ�ʽ:");
        scanf("%d", &x);
        fflush(stdin);
        switch (x)
        {
        case 1:
            printf("\t\t\t����������鼮���:");
            gets(b);
            fflush(stdin);
            printf("\t\t\t�������������:");
            scanf("%d", &i);
            fflush(stdin);
            lend(M, b, i, r3);
            flag = 0;
            break;
        case 2:
            printf("\t\t\t����������鼮����:");
            gets(b);
            fflush(stdin);
            printf("\t\t\t�������������:");
            scanf("%d", &i);
            fflush(stdin);
            lend1(M, b, i, r3);
            flag = 0;
            break;
        default:
            system("cls");
            color(4);
            printf("\t\t\t�����ڴ˲�����������ѡ�񣡣���\n\n");
            color(16);
            flag = 1;
            break;
        }
    } while (flag);
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
        printf("�����ڴ���!\n\n");
        color(16);
        return 0;
    }
    if (pre->now == 0)
    {
        system("cls");
        printf("\t\t\t���\t����\t����\tʣ����\t�����\n");
        printf("\t\t\t%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("\t\t\t�����ѱ����꣡\n\n");
        color(16);
        return 0;
    }
    if (pre->now < i)
    {
        system("cls");
        printf("\t\t\t���\t����\t����\tʣ����\t�����\n");
        printf("%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("\t\t\t�����治��%d����\n\n", i);
        color(16);
        return 0;
    }
    inf[r4].bookn = pre->bookflag;
    if (inf[r4].booknu[inf[r4].bookn] + i > 2)
    {
        printf("����ǰ���ڱ���Ľ�����Ϣ����\n");
        printf("\t\t\t���\t����\t����\t������\n");
        printf("\t\t\t%s\t%s\t%s\t", pre->num, pre->name, pre->author);
        color(4);
        printf("%d\t", inf[r4].booknu[inf[r4].bookn]);
        color(16);
        color(4);
        printf("\t\t\tһ�������ֻ�ܽ�2������\n");
        color(16);
        return 0;
    }
    pre->now -= i;
    system("cls");
    printf("\t\t\t���ĵ��鼮��Ϣ����:\n");
    printf("\t\t\t���\t����\t����\t��������\tʣ����\t�黹ʱ��\n");
    printf("\t\t\t %s\t %s\t %s\t  %d\t\t%d\t%d��%d��%d��\n", pre->num, pre->name, pre->author, i, pre->now, 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("\t\t\t�ɹ��������!\n\n");
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
        printf("\t\t\t�����ڴ���!\n\n");
        color(16);
        return 0;
    }
    if (pre->now == 0)
    {
        printf("\t\t\t���\t����\t����\tʣ����\t�����\n");
        printf("\t\t\t%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("\t\t\t�����ѱ����꣡\n\n");
        color(16);
        return 0;
    }
    if (pre->now < i)
    {
        printf("\t\t\t���\t����\t����\tʣ����\t�����\n");
        printf("\t\t\t%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, pre->now, pre->all);
        color(4);
        printf("\t\t\t�����治��%d����\n\n", i);
        color(16);
        return 0;
    }
    inf[r4].bookn = pre->bookflag;
    if (inf[r4].booknu[inf[r4].bookn] + i > 2)
    {
        printf("����ǰ���ڱ���Ľ�����Ϣ����\n");
        printf("\t\t\t���\t����\t����\t������\n");
        printf("\t\t\t%s\t%s\t%s\t", pre->num, pre->name, pre->author);
        color(4);
        printf("%d\t", inf[r4].booknu[inf[r4].bookn]);
        color(16);
        color(4);
        printf("\t\t\tһ�������ֻ�ܽ�2������\n");
        color(16);
        return 0;
    }
    pre->now -= i;
    system("cls");
    printf("\t\t\t���ĵ��鼮��Ϣ����:\n");
    printf("\t\t\t���\t����\t����\t��������\tʣ����\t�黹ʱ��\n");
    printf("\t\t\t %s\t %s\t %s\t  %d\t\t%d\t%d��%d��%d��\n", pre->num, pre->name, pre->author, i, pre->now, 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("\t\t\t�ɹ��������!\n\n");
    inf[r4].bookn = pre->bookflag;
    inf[r4].y[inf[r4].bookn] = 1900 + p->tm_year;
    inf[r4].m[inf[r4].bookn] = 1 + p->tm_mon;
    inf[r4].d[inf[r4].bookn] = p->tm_mday;
    strcpy(inf[r4].booknum[inf[r4].bookn], pre->num);
    inf[r4].booknu[inf[r4].bookn] += i;
    return 1;
}
void switchr(LinkList &M, int r3) //ѡ��黹�鼮��ʽ
{
    int flag = 0;
    system("cls");
    do
    {
        printf("\n\t\t\t\t\t\t���鷽ʽ\n"
               "\t\t\t\t\t\t 1.���\n"
               "\t\t\t\t\t\t 2.����\n");
        int x, i;
        char b[MAXSIZE];
        printf("\t\t\t��ѡ���鷽ʽ:");
        scanf("%d", &x);
        fflush(stdin);
        switch (x)
        {
        case 1:
            printf("\t\t\t������黹�鼮���:");
            gets(b);
            fflush(stdin);
            printf("\t\t\t������黹����:");
            scanf("%d", &i);
            fflush(stdin);
            returnb(M, b, i, r3);
            flag = 0;
            break;
        case 2:
            printf("\t\t\t������黹�鼮����:");
            gets(b);
            fflush(stdin);
            printf("\t\t\t������黹����:");
            scanf("%d", &i);
            fflush(stdin);
            returnb1(M, b, i, r3);
            flag = 0;
            break;
        default:
            system("cls");
            color(4);
            printf("\t\t\t�����ڴ˲�����������ѡ�񣡣���\n\n");
            color(16);
            flag = 1;
            break;
        }
    } while (flag);
}

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
        printf("\t\t\t�����ڴ���!\n\n");
        color(16);
        return 0;
    }
    inf[r4].bookn = pre->bookflag;
    if (inf[r4].booknu[inf[r4].bookn] < i)
    {
        printf("\t\t\t���\t����\t����\t������\t�����\n");
        printf("\t\t\t%s\t%s\t%s\t", pre->num, pre->name, pre->author);
        color(4);
        printf("%d\t", inf[r4].booknu[inf[r4].bookn]);
        color(16);
        printf("%d\n", pre->all);
        color(4);
        printf("\t\t\t�黹����������Ӧ�еĽ������������Ƿ�ȷ������\n\n");
        color(16);
        return 0;
    }
    pre->now += i;
    system("cls");
    printf("\t\t\t�黹���鼮��Ϣ����:\n");
    printf("\t\t\t���\t����\t����\t�黹����\tʣ����\n");
    printf("\t\t\t %s\t %s\t %s\t  %d\t\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("\t\t\t�ɹ��黹����!\n\n");
    inf[r4].bookn = pre->bookflag;
    strcpy(inf[r4].booknum[inf[r4].bookn], "");
    inf[r4].booknu[inf[r4].bookn] -= i;
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
        printf("\t\t\t�����ڴ���!\n\n");
        color(16);
        return 0;
    }
    if (inf[r4].booknu[inf[r4].bookn] < i)
    {
        printf("\t\t\t���\t����\t����\t������\t�����\n");
        printf("\t\t\t%s\t%s\t%s\t", pre->num, pre->name, pre->author);
        color(4);
        printf("%d\t", inf[r4].booknu[inf[r4].bookn]);
        color(16);
        printf("%d\n", pre->all);
        color(4);
        printf("\t\t\t�黹����������Ӧ�еĽ������������Ƿ�ȷ������\n\n");
        color(16);
        return 0;
    }
    pre->now += i;
    system("cls");
    printf("\t\t\t�黹���鼮��Ϣ����:\n");
    printf("\t\t\t���\t����\t����\t�黹����\tʣ����\n");
    printf("\t\t\t%s\t%s\t%s\t%d\t%d\n", pre->num, pre->name, pre->author, i, pre->now);
    printf("\t\t\t�ɹ��黹����!\n\n");
    inf[r4].bookn = pre->bookflag;
    strcpy(inf[r4].booknum[inf[r4].bookn], "");
    inf[r4].booknu[inf[r4].bookn] -= i;
    return 1;
}
int show(LinkList &L) //��ʾͼ����������鼮
{
    LinkList pre;
    int k = 0;
    pre = L;
    printf("\n\t\t\t\t\t���еĵ��鼮��Ϣ����:\n");
    printf("\t\t\t\t\t���\t����\t����\tʣ����\t�����\n");
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
        printf("\t\t\tͼ�����û���飬��ɱ��鼮���\n");
        color(16);
    }
    printf("\n");
    return 1;
}
int own(LinkList &L, int r3) //�鿴�Լ�����鼮�Լ��黹ʱ��
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
        }
        if (!strcmp(pre->num, inf[r3].booknum[inf[r3].bookn]) && l == 0)
        {
            printf("\n����ĵ��鼮��Ϣ����\n");
            printf("\t\t\t���\t���\t����\t����\t��������\tͼ���ʣ����\t�黹����\n\n");
            l++;
        }
        if (!strcmp(pre->num, inf[r3].booknum[inf[r3].bookn]))
        {
            ++k;
            printf("\t\t\t %d\t %s\t %s\t %s\t  %d\t\t       %d\t%d��%d��%d��\n", k, pre->num, pre->name, pre->author, inf[r3].booknu[inf[r3].bookn], pre->now, inf[r3].y[inf[r3].bookn], inf[r3].m[inf[r3].bookn], inf[r3].d[inf[r3].bookn]);
            j++;
        }
        if (j == 0)
        {
            color(4);
            printf("\n\t\t\t\t\t\t�㻹û�н��飡\n\n");
            color(16);
            return 0;
        }

        pre = pre->next;
    }
    printf("\n");
    return 1;
}
int bookdataw(LinkList &L) //�洢ͼ����������鼮����,���ݴ洢�ڵ�ǰĿ¼��bookdata.csv,����excel�༭
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
            fprintf(fp, "���Ǻ�,���,����,����,�ִ���,����\n");
        pre = pre->next;
        fprintf(fp, "%d,%s,%s,%s,%d,%d", pre->bookflag, pre->num, pre->name, pre->author, pre->now, pre->all);
        flag3++;
    }
    fclose(fp);
    return 1;
}
int bookdatar(LinkList &L) //��ȡ�洢ͼ����������鼮������
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
            if (line != NULL)
            {
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
    }
    fclose(fp);
    return 1;
}
int userdataw(LinkList &L, int r3) //�洢�û������鼮����,���ݴ洢�ڵ�ǰĿ¼��user.csv,����excel�༭
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
                fprintf(fp, "���Ǻ�,���,����,�黹��,�黹��,�黹��\n");
            fprintf(fp, "%d,%s,%d,%d,%d,%d", inf[r3].bookn, inf[r3].booknum[inf[r3].bookn], inf[r3].booknu[inf[r3].bookn], inf[r3].y[inf[r3].bookn], inf[r3].m[inf[r3].bookn], inf[r3].d[inf[r3].bookn]);
            flag3++;
        }

        pre = pre->next;
    }
    fclose(fp);
    return 1;
}
int userdatar(int r3) //��ȡ�û����������鼮����
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
            if (line != NULL)
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
void color(short x) //�ı�������ɫ
{
    if (x >= 0 && x <= 15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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
