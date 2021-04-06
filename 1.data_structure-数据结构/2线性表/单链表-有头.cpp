#include "iostream"
using namespace std;

// 有头结点用的多
#define ElemType int

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) // 内存不足
        return false;
    L->next = NULL; // 数据清楚
    return true;
}

// 头插法创建单链表
LinkList List_HeadInserter(LinkList &L)
{
    LNode *s;
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL; // 初始化为空，避免指向现有内存
    cin >> x;
    while (x != -9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}

// 尾插法创建单链表
LinkList List_TailInserter(LinkList &L)
{
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s, *r = L; // 尾指针r，中间指针s
    cin >> x;
    while (x != -9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = NULL;
    return L;
}

// 按位查找，返回第i个元素
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p = L;
    for (int j = 0; p != NULL && j < i - 1; p = p->next, j++)
        ;
    return p;
}

// 按值查找，找到数据域==e的节点
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    // for (LNode *p = L->next; p != NULL && p->data != e; p = p->next)
    //     ;
    return p;
}

// 在节点后插入
bool InsertNextNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 在节点前插入
bool InsertBeforeNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

int GetLength(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 在第i个位置插入
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    LNode *p = GetElem(L, i - 1);
    return InsertNextNode(p, e);
}

// 删除第i个节点
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1)
        return false;
    LNode *p = GetElem(L, i - 1);
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;
    e = p->next->data;
    p->next = p->next->next;
    return true;
}

// 删除指定节点p
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    if (p->next == NULL)
    {
        // 必须遍历一便
    }
    p->data = p->next->data;
    p->next = p->next->next;
    return true;
}

bool Empty(LinkList L)
{
    return L->next == NULL;
}

void test()
{
    LinkList L;
    InitList(L);
}

int main()
{
    test();
}