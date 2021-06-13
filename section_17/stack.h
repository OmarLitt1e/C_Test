/* stack.h -- 栈 */
/* LIFO */
#ifndef _STACK_H_
#define _STACK_H_
#include <stdint.h>
#include <stdbool.h>

#define StackSize 200

/* 根据具体情况重新定义 Item */
typedef struct item {
    int8_t Character;
}Item;

typedef struct trnode {
    Item item;
    struct trnode * former; /* 指向前一项 */
}StackItem;

typedef struct tree{
    StackItem * tail;/* 指向栈尾 */
    int size; /* 栈的项数 */
}Stack;

/* 操作： 初始化队列，将栈的内容一次弹出，直到栈空 */
/* 前提条件： pq 指向一个栈尾 */
/* 后置条件： 栈被初始化为空 */
void InitializeStack(Stack * pq);

/* 操作： 检查栈是否已满 */
/* 前提条件： pq 指向之前被初始化的栈的栈尾 */
/* 后置条件： 如果栈已满则返回true，否则返回false */
bool StackIsFull(const Stack * pq);

/* 操作： 检查栈是否为空 */
/* 前提条件： pq 指向之前被初始化的栈的栈尾 */
/* 后置条件： 如果栈为空则返回true，否则返回false */
bool StackIsEmpty(const Stack *pq);

/* 操作： 确定栈中的项数 */
/* 前提条件： pq 指向之前被初始化的栈的栈尾 */
/* 后置条件： 返回栈中的项数 */
int StackItemCount(const Stack * pq);

/* 操作： 在栈尾添加项 */
/* 前提条件： pq 指向之前被初始化的栈的栈尾 */
/* item是要被添加在栈尾的项 */
/* 后置条件： 如果栈未满，item将被添加在队列的末尾， */
/* 该函数返回true；否则，队列不改变，该函数返回false*/
bool EnStack(Item item, Stack * pq);

/* 操作： 从栈尾删除项 */
/* 前提条件： pq 指向之前被初始化的栈的栈尾 */
/* 后置条件： 如果栈不为空，栈尾的item将被拷贝到*pitem中 */
/* 并被删除，且函数返回true； */
/* 如果该操作使得栈为空，则重置栈为 空 */
/* 如果栈在操作前为空，该函数返回false */
bool DeStack(Stack * pq);

/* 操作： 清空栈 */
/* 前提条件： pq 指向之前被初始化的栈的栈尾 */
/* 后置条件： 栈被清空 */
//void EmptyTheStack(Stack * pq);







#endif
