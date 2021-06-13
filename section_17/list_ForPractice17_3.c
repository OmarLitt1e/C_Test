/* list.c -- ֧����������ĺ��� */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "list_ForPractice17_3.h"

///* �ֲ�����ԭ�� */
//static void CopyToNode(Item item, Node * pnode);

/* �ӿں��� */
/* ����������Ϊ�� */
void InitializeList(List * const plist)
{
    plist->items=0;
}

/* �������Ϊ�գ�����true */
bool ListIsEmpty(const List * const plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

/* �����������������true */
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

/* ���ؽڵ������ */
unsigned int ListItemCount(const List * const plist)
{
    return (unsigned int)(plist->items);
}

/* ����������Ľڵ㣬�������������plistָ�������ĩβ��������ʵ �֣� */
bool AddItem(Item item, List * const plist)
{
//    Item * pnew;
    //List * scan = plist;
//    pnew = (Item *) malloc(sizeof(Item));
//    if (pnew == NULL)
//        return false; /* ʧ��ʱ�˳����� */
    //CopyToNode(item, pnew);
    (plist->entries)[plist->items] = item;
    (plist->items)++;
    return true;
}

/* ����ÿ���ڵ㲢ִ��pfunָ��ĺ��� */
void Traverse(const List * const plist, void(*pfun)(Item item))
{
//    uint8_t i;
//    for(i=0;i<plist->items;i++)
    uint8_t i;
    for(i=0;i<plist->items;i++)
    {
        (*pfun)((plist->entries)[i]); /* �Ѻ���Ӧ���������е��� */

    }
}

/* �ͷ���malloc()������ڴ� */
/* ��������ָ��ΪNULL */
void EmptyTheList(List * const plist)
{
    plist->items=0;
}

///* �ֲ��������� */
///* ��һ��������ڵ��� */
//static void CopyToNode(Item item, Node * pnode)
//{
//    pnode->item = item; /* �����ṹ */
//}
