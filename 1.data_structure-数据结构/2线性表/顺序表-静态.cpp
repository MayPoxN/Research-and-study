#include "iostream"
using namespace std;

#define MAX_SIZE 10
#define ElementType int

////////////////////////////////
//  静态分配
typedef struct
{
    ElementType data[MAX_SIZE];
    int length;
} SqList; // sequenceList

void IniiList(SqList &L)
{
    for (int i = 0; i < MAX_SIZE; i++)
        L.data[i] = 0;
    L.length = 0;
}

bool ListInsert(SqList &L, int i, ElementType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MAX_SIZE)
        return false;

    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElementType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

ElementType GetElem(SqList &L, int i)
{
    return L.data[i-1];
}

void print(SqList &L)
{
    for (int i = 0; i < L.length; i++)
        printf(" data[%d]=%d\n", i, L.data[i]);
}

bool assert(bool flag, ElementType value = NULL)
{
    if (flag == true)
        cout << "Successful!" << endl;
    else
        cout << "Error!" << endl;
    return flag;
}

int main()
{
    SqList L;
    IniiList(L);
    {
        ListInsert(L, 1, 5);
        ListInsert(L, 1, 4);
        ListInsert(L, 1, 3);
        ListInsert(L, 1, 2);
        ListInsert(L, 1, 1);
    }
    assert(ListInsert(L, 3, 3));

    ElementType e; //用于将被删除的值带回来

    bool flag = assert(ListDelete(L, 3, e), e);
    if (flag)
        cout << "You have Delete " << e << endl;

    print(L);
    return 0;
}