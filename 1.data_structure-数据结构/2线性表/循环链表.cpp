#include "iostream"
using namespace std;

#define ElemType int

////////////////////////////////
// 循环单链表
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InitLinkList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = L;
    return true;
}

bool Empty(LinkList L)
{
    return L->next == L;
}

bool isTail(LinkList L, LNode *p)
{
    return p->next == L;
}
////////////////////////////////

////////////////////////////////
// 循环双链表
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->next = L;
    L->prior = L;
    return true;
}

bool EmptyD(DLinkList L)
{
    return L->next == L;
}

bool isTailD(DLinkList L, DNode *p)
{
    return p->next == L;
}
////////////////////////////////