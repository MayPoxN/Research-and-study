#include "iostream"
using namespace std;

#define ElemType int
#define MAX_SIZE 10

// 以上操作等同于下面
// struct Node
// {
//     ElemType data;
//     int next;
// };
// typedef struct Node SLL[MAX_SIZE];

typedef struct
{
    ElemType data;
    int next;
} SLL[MAX_SIZE];

void InitSLL()
{
}

void testSLinkList()
{
    SLL a; // 在这里SLL定义a代表是一个静态链表（数组）
}