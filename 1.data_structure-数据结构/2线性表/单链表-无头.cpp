#include "iostream"
using namespace std;

// 无头结点用的少
#define ElemType int

typedef struct LNode
{
    ElemType dataType;
    struct LNode *next;
} LNode, *LinkList;
//  在这里LNode*和LinkList是同一个东西
//  但是一个强调节点，一个强调链表
//  在这里，LNode被声明为一个节点，LinkList被声明为一个指针
//  以上结构等同于下面
// struct LNode
// {
//     ElemType dataType;
//     struct LNode *next;
// };
// typedef struct LNode LNode;
// typedef struct LNode *LinkList;
//  下面的返回类型是LNode的指针（LNode*）后面传入的是LinkList，其实是一样的

LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

bool InitList(LinkList &L)
{
    L = NULL; // 清除数据
    return false;
}

bool Empty(LinkList L)
{
    return L == NULL;
}

void test()
{
    LinkList L;
    InitList(L);
}
