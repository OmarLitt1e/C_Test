
/* list.h -- ���������͵�ͷ�ļ� */
#ifndef LIST_FORPRACTICE17_3_H_
#define LIST_FORPRACTICE17_3_H_
#include <stdbool.h> /* C99���� */
/* �ض���������� */
#define TSIZE 45 /* �����Ӱ���������С */
#define MAXSIZE 100
struct film {
    char title[TSIZE];
    int rating;
};
/* һ�����Ͷ��� */
typedef struct film Item;
//typedef struct node {
//    Item item;
//    struct node * next;
//}Node;
//typedef Node * List;
typedef struct list {
    Item entries[MAXSIZE]; /* �ں�������� */
    int items; /* list�е����� */
} List;

/* ����ԭ�� */
/* ������ ��ʼ��һ���� �� */
/* ǰ�������� plistָ��һ���� �� */
/* ���������� �����ʼ��Ϊ �� */
void InitializeList(List * const plist);

/* ������ ȷ�������Ƿ�Ϊ�ն��壬plistָ��һ���ѳ�ʼ������ �� */
/* ���������� �������Ϊ�գ��ú�������true�����򷵻� false */
bool ListIsEmpty(const List * const plist);

/* ������ ȷ�������Ƿ�������plistָ��һ���ѳ�ʼ������ �� */
/* ���������� ��������������ú��������棻���򷵻� �� */
bool ListIsFull(const List * const plist);

/* ������ ȷ�������е�����, plistָ��һ���ѳ�ʼ������ �� */
/* ���������� �ú������������е��� �� */
unsigned int ListItemCount(const List * const plist);

/* ������ �������ĩβ��� �� */
/* ǰ�������� item��һ����������������, plistָ��һ���ѳ�ʼ�� ������ */
/* ���������� ������ԣ��ú���������ĩβ���һ����ҷ��� true�����򷵻�false */
bool AddItem(Item item, List * const plist);

/* ������ �Ѻ��������������е�ÿһ �� */
/* plistָ��һ���ѳ�ʼ������ �� */
/* pfunָ��һ���������ú�������һ��Item���͵Ĳ����� ���޷���ֵ */
/* ���������� pfunָ��ĺ��������������е�ÿһ��һ �� */
void Traverse(const List * const plist, void(*pfun)(Item item));

/* ������ �ͷ��ѷ�����ڴ棨����е� ���� */
/* plistָ��һ���ѳ�ʼ������ �� */
/* ���������� �ͷ���Ϊ�������������ڴ棬��������Ϊ �� */
void EmptyTheList(List * const plist);





#endif // LIST_H_
