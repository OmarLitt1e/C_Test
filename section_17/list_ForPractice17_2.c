/* list.c -- 支持链表操作的函数 */
#include <stdio.h>
#include <stdlib.h>
#include "list_ForPractice17_2.h"

/* 局部函数原型 */
static void CopyToNode(Item item, Node * pnode);

/* 接口函数 */
/* 把链表设置为空 */
void InitializeList(List * plist)
{
    plist->head = NULL;
    plist->end = NULL;
}

/* 如果链表为空，返回true */
bool ListIsEmpty(const List * plist)
{
    if (plist->end == NULL)
        return true;
    else
        return false;
}

/* 如果链表已满，返回true */
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;
    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    return full;
}

/* 返回节点的数量 */
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = plist->head; /* 设置链表的开始 */
    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next; /* 设置下一个节点 */
    }
    return count;
}

/* 创建储存项的节点，并将其添加至由plist指向的链表末尾（较慢的实 现） */
bool AddItem(Item item, List * plist)
{
    Node * pnew;
    //List * scan = plist;
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false; /* 失败时退出函数 */
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (plist->head == NULL) /* 空链表，所以把 */
    {
        plist->head = pnew; /* pnew放在链表的开头 */
        plist->head->next = NULL; /* pnew放在链表的开头 */
        plist->end = pnew; /* 把pnew添加到链表的末尾 */
    }
    else
    {
        plist->end->next = pnew; /* 把pnew添加到链表的末尾 */
        plist->end = pnew; /* 把pnew添加到链表的末尾 */
    }
    return true;
}

/* 访问每个节点并执行pfun指向的函数 */
void Traverse(const List * plist, void(*pfun)(Item item))
{
    Node * pnode = plist->head; /* 设置链表的开始 */
    while (pnode != NULL)
    {
        (*pfun)(pnode->item); /* 把函数应用于链表中的项 */
        pnode = pnode->next; /* 前进到下一项 */
    }
}

/* 释放由malloc()分配的内存 */
/* 设置链表指针为NULL */
void EmptyTheList(List * plist)
{
    Node * psave, * Temp;
    psave = plist->head;

    while (psave->next != NULL)
    {
        Temp = psave;
        psave = psave->next; /* 保存下一个节点的地址 */
        free(Temp); /* 释放当前节点 */
    }
}

/* 局部函数定义 */
/* 把一个项拷贝到节点中 */
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item; /* 拷贝结构 */
}
