#include "iostream"
using namespace std;

#define MAX_SIZE 10
#define ElemType int

typedef struct
{
    ElemType data[MAX_SIZE];
    int front, rear;
    // int size;
    // 可以设置变量size确定队列里面有多少元素，这样就不会浪费空间
    // int tag; tag->0,1分别表示删除/插入
    // 如果tag->1可以知道是插入，队列满
    // 如果tag->0可以知道是删除，队列空
} SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
}

bool QueueIsEmpty(SqQueue Q)
{
    return Q.front == Q.rear;
    // 同一个位置代表队列为空
}

bool QueueIsFull(SqQueue Q)
{
    return (Q.rear + 1) % MAX_SIZE == Q.front;
    // 队尾指针的下一个位置是队头，代表队列满了
    // 牺牲一个空间
}

int CountElements(SqQueue Q)
{
    return (MAX_SIZE + Q.rear - Q.front) % MAX_SIZE;
}

bool Enqueue(SqQueue &Q, ElemType e)
{
    if (QueueIsFull(Q))
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAX_SIZE;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &e)
{
    if (QueueIsEmpty(Q))
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    return true;
}

bool GetHead(SqQueue &Q, ElemType &e)
{
    if (QueueIsEmpty(Q))
        return false;
    e = Q.data[Q.front];
    return true;
}

void testQueue()
{
    SqQueue Q;
}