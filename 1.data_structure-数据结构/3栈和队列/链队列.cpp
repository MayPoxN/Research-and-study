#include "iostream"
using namespace std;

#define MAX_SIZE 10
#define ElemType int

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode;
// 队列节点

typedef struct
{
    LinkNode *front, *rear;
    // int length;
    // 长度
} LinkQueue;

void InitQueue(LinkQueue &Q)
{
    // 生成一个头节点
    // 初始化 front、rear都指向头节点
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q)
{
    return Q.front == Q.rear;
    // return Q.front->next == NULL;
}

void Enqueue(LinkQueue &Q, ElemType e)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &e)
{
    if (Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}