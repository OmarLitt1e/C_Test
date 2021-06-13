/* queue.h -- Queue�Ľӿ� */
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

#define For_List_17_6   176
#define For_List_17_9   179

#define CurrentItemOption For_List_17_6

#if (CurrentItemOption==For_List_17_6)

    // ���������Item���͵Ķ��壬����
    typedef int Item; // ����use_q.c

#elif (CurrentItemOption==For_List_17_9)

    // ���������Item���͵Ķ��壬����
    typedef struct item {
        long arrive; //һλ�˿ͼ�����е�ʱ��
        int processtime; //�ù˿���ѯʱ���ѵ�ʱ��
    } Item;

#endif


#define MAXQUEUE 10

typedef struct node {
    Item item;
    struct node * next;
}Node;

typedef struct queue {
    Node * front; /* ָ����������ָ�� */
    Node * rear; /* ָ�����β���ָ�� */
    int items; /* �����е����� */
}Queue;

/* ������ ��ʼ������ */
/* ǰ�������� pq ָ��һ������ */
/* ���������� ���б���ʼ��Ϊ�� */
void InitializeQueue(Queue * pq);

/* ������ �������Ƿ����� */
/* ǰ�������� pq ָ��֮ǰ����ʼ���Ķ��� */
/* ���������� ������������򷵻�true�����򷵻�false */
bool QueueIsFull(const Queue * pq);

/* ������ �������Ƿ�Ϊ�� */
/* ǰ�������� pq ָ��֮ǰ����ʼ���Ķ��� */
/* ���������� �������Ϊ���򷵻�true�����򷵻�false */
bool QueueIsEmpty(const Queue *pq);

/* ������ ȷ�������е����� */
/* ǰ�������� pq ָ��֮ǰ����ʼ���Ķ��� */
/* ���������� ���ض����е����� */
int QueueItemCount(const Queue * pq);

/* ������ �ڶ���ĩβ����� */
/* ǰ�������� pq ָ��֮ǰ����ʼ���Ķ��� */
/* item��Ҫ������ڶ���ĩβ���� */
/* ���������� ������в�Ϊ�գ�item��������ڶ��е�ĩ β�� */
/* �ú�������true�����򣬶��в��ı䣬�ú�������false*/
bool EnQueue(Item item, Queue * pq);

/* ������ �Ӷ��еĿ�ͷɾ���� */
/* ǰ�������� pq ָ��֮ǰ����ʼ���Ķ��� */
/* ���������� ������в�Ϊ�գ������׶˵�item����������*pitem�� */
/* ����ɾ�����Һ�������true�� */
/* ����ò���ʹ�ö���Ϊ�գ������ö���Ϊ �� */
/* ��������ڲ���ǰΪ�գ��ú�������false */
bool DeQueue(Item *pitem, Queue * pq);

/* ������ ��ն��� */
/* ǰ�������� pq ָ��֮ǰ����ʼ���Ķ��� */
/* ���������� ���б���� */
void EmptyTheQueue(Queue * pq);



#endif // _QUEUE_H_

