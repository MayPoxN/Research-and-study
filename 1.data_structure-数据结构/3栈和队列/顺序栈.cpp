#include "iostream"
using namespace std;

#define MAX_SIZE 10
#define ElemType int 

typedef struct
{
    ElemType data[MAX_SIZE];
    int top;
} SqStack;

void InitStack(SqStack &S)
{
    S.top = -1; // 栈的指针指向栈顶元素的数组下标
}

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

bool Push(SqStack &S, ElemType e)
{
    if (S.top == MAX_SIZE - 1)
        return false;
    S.data[++S.top] = e;
    return true;
}

bool Pop(SqStack &S, ElemType &e)
{
    if (S.top == -1)
        return false;
    e = S.data[S.top--];
    return true;
}

bool GetTop(SqStack &S, ElemType &e)
{
    if (S.top == -1)
        return false;
    e = S.data[S.top];
    return true;
}

void testStack()
{
    SqStack S;
}

int main(int argc, char **argv)
{
    testStack();
}
