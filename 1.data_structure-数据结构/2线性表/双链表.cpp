#include "iostream"
using namespace std;

#define ElemType int

typedef struct DNode
{
    ElemType dataType;
    struct DNode *prioir, *next;
} DNode, *DLinkList;

bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode)); // 分配头节点
    if (L == NULL)
        return false;
    L->prioir = NULL;
    L->next = NULL;
    return true;
}

bool Empty(DLinkList L)
{
    return L->next == NULL;
}

// 把s插入到p之后
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    s->prioir = p;
    if (p->next != NULL)
        p->next->prioir = s;
    p->next = s;
    return true;
}

// 删除p的后继节点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL || p->next == NULL)
        return false;
    p->next = p->next->next;
    if (p->next != NULL)
        p->next->prioir = p;
    return true;
}

void testDLinkList()
{
    DLinkList L;
    InitDLinkList(L);
}