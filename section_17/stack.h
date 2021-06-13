/* stack.h -- ջ */
/* LIFO */
#ifndef _STACK_H_
#define _STACK_H_
#include <stdint.h>
#include <stdbool.h>

#define StackSize 200

/* ���ݾ���������¶��� Item */
typedef struct item {
    int8_t Character;
}Item;

typedef struct trnode {
    Item item;
    struct trnode * former; /* ָ��ǰһ�� */
}StackItem;

typedef struct tree{
    StackItem * tail;/* ָ��ջβ */
    int size; /* ջ������ */
}Stack;

/* ������ ��ʼ�����У���ջ������һ�ε�����ֱ��ջ�� */
/* ǰ�������� pq ָ��һ��ջβ */
/* ���������� ջ����ʼ��Ϊ�� */
void InitializeStack(Stack * pq);

/* ������ ���ջ�Ƿ����� */
/* ǰ�������� pq ָ��֮ǰ����ʼ����ջ��ջβ */
/* ���������� ���ջ�����򷵻�true�����򷵻�false */
bool StackIsFull(const Stack * pq);

/* ������ ���ջ�Ƿ�Ϊ�� */
/* ǰ�������� pq ָ��֮ǰ����ʼ����ջ��ջβ */
/* ���������� ���ջΪ���򷵻�true�����򷵻�false */
bool StackIsEmpty(const Stack *pq);

/* ������ ȷ��ջ�е����� */
/* ǰ�������� pq ָ��֮ǰ����ʼ����ջ��ջβ */
/* ���������� ����ջ�е����� */
int StackItemCount(const Stack * pq);

/* ������ ��ջβ����� */
/* ǰ�������� pq ָ��֮ǰ����ʼ����ջ��ջβ */
/* item��Ҫ�������ջβ���� */
/* ���������� ���ջδ����item��������ڶ��е�ĩβ�� */
/* �ú�������true�����򣬶��в��ı䣬�ú�������false*/
bool EnStack(Item item, Stack * pq);

/* ������ ��ջβɾ���� */
/* ǰ�������� pq ָ��֮ǰ����ʼ����ջ��ջβ */
/* ���������� ���ջ��Ϊ�գ�ջβ��item����������*pitem�� */
/* ����ɾ�����Һ�������true�� */
/* ����ò���ʹ��ջΪ�գ�������ջΪ �� */
/* ���ջ�ڲ���ǰΪ�գ��ú�������false */
bool DeStack(Stack * pq);

/* ������ ���ջ */
/* ǰ�������� pq ָ��֮ǰ����ʼ����ջ��ջβ */
/* ���������� ջ����� */
//void EmptyTheStack(Stack * pq);







#endif
