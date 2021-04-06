#include "iostream"
using namespace std;

#define InitSize 10
#define ElementType int

////////////////////////////////
//  动态分配
typedef struct
{
    ElementType *data;
    int MaxSize;
    int length;
} SeqList; // sequenceList

//  使用malloc和free来进行内存空间的申请和释放
//  L.data = (ElementType *)malloc(sizeof(ElementType)*InitSize);

void IniiList(SeqList &L)
{
    L.data = (ElementType *)malloc(sizeof(ElementType) * InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len)
{
    ElementType *p = L.data;
    L.data = (ElementType *)malloc((L.MaxSize + len) * sizeof(ElementType));
    for (int i = 0; i < L.length; i++)
        L.data[i] = p[i];
    L.MaxSize = L.MaxSize + len;
    free(p);
}

ElementType GetElem(SeqList &L, int i)
{
    return L.data[i - 1];
}

int LocateElem(SeqList &L, ElementType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0; // 这里返回的是位序，排名，不是数组下标
}

void print(SeqList &L)
{
    for (int i = 0; i < L.length; i++)
        printf(" data[%d]=%d\n", i, L.data[i]);
}

int main()
{
    SeqList L;
    IniiList(L);
    IncreaseSize(L, 5);
    print(L);
    return 0;
}