/* list.c -- 支持链表操作的函数 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "list_ForPractice17_3.h"

///* 局部函数原型 */
//static void CopyToNode(Item item, Node * pnode);

/* 接口函数 */
/* 把链表设置为空 */
void InitializeList(List * const plist)
{
    plist->items=0;
}

/* 如果链表为空，返回true */
bool ListIsEmpty(const List * const plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

/* 如果链表已满，返回true */
bool ListIsFull(const List * const plist)
{
    Item * pt;
    bool full;
    pt = (Item *)malloc(sizeof(Item));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    return full;
}

/* 返回节点的数量 */
unsigned int ListItemCount(const List * const plist)
{
    return (unsigned int)(plist->items);
}

/* 创建储存项的节点，并将其添加至由plist指向的链表末尾（较慢的实 现） */
bool AddItem(Item item, List * const plist)
{
//    Item * pnew;
    //List * scan = plist;
//    pnew = (Item *) malloc(sizeof(Item));
//    if (pnew == NULL)
//        return false; /* 失败时退出函数 */
    //CopyToNode(item, pnew);
    (plist->entries)[plist->items] = item;
    (plist->items)++;
    return true;
}

/* 访问每个节点并执行pfun指向的函数 */
void Traverse(const List * const plist, void(*pfun)(Item item))
{
//    uint8_t i;
//    for(i=0;i<plist->items;i++)
    uint8_t i;
    for(i=0;i<plist->items;i++)
    {
        (*pfun)((plist->entries)[i]); /* 把函数应用于链表中的项 */

    }
}

/* 释放由malloc()分配的内存 */
/* 设置链表指针为NULL */
void EmptyTheList(List * const plist)
{
    plist->items=0;
}

///* 局部函数定义 */
///* 把一个项拷贝到节点中 */
//static void CopyToNode(Item item, Node * pnode)
//{
//    pnode->item = item; /* 拷贝结构 */
//}
