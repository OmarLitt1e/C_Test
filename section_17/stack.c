
#include "stack.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> // 提供 rand() 和 srand() 的原型

void InitializeStack(Stack * pq)
{
    while((pq->tail)->former != NULL)
    {
        putchar( (pq->tail->item).Character );
        StackItem *TempPoint;
        TempPoint = pq->tail;
        pq->tail = pq->tail->former;

        free(TempPoint);
    }
    puts("");
    pq->size = 0;
}

bool StackIsFull(const Stack * pq)
{
    if( pq->size == StackSize)
        return true;
    else
        return false;
}

bool StackIsEmpty(const Stack *pq)
{
    if( pq->size == 0)
        return true;
    else
        return false;
}

int StackItemCount(const Stack * pq)
{
    return pq->size;
}

bool EnStack(Item item, Stack * pq)
{
    if(StackIsFull(pq))
    {
        puts("stack is full");
        return false;
    }
    StackItem *pnew;
    pnew = (StackItem *) malloc(sizeof(StackItem));
    if (pnew == NULL)
        return false;

    pnew->item = item;
    pnew->former = pq->tail;
    pq->tail = pnew;
    pq->size += 1;
    return true;
}

bool DeStack(Stack * pq)
{
    if(StackIsEmpty(pq))
    {
        puts("Stack is already empty");
        return false;
    }

    StackItem *TempPoint;
    TempPoint = pq->tail;
    pq->tail = pq->tail->former;

    free(TempPoint);

    pq->size -= 1;
    return true;
}

