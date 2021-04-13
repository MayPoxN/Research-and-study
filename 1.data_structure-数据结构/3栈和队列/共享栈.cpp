#include "iostream"
using namespace std;

#define MAX_SIZE 10
#define ElemType int

typedef struct
{
    ElemType data[MAX_SIZE];
    int top0;
    int top1;
} ShStack;

void InitShStack(ShStack *S)
{
    S->top0 = -1;
    S->top1 = MAX_SIZE;
    // 栈满条件：top0+1==top1
}