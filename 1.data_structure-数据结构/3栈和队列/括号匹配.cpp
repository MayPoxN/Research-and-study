#include "iostream"
using namespace std;

////////////////////////////////
#define MAX_SIZE 1024
#define ElemType char

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
////////////////////////////////

bool BracketChecker(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            Push(S, str[i]);
        else
        {
            if (StackEmpty(S))
                return false;
            char topElem;
            Pop(S, topElem);
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == ']' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S);
}

int main(int argc, char **argv)
{
    cout << "Hello World!" << endl;
    char a[32] = "(){}(){}";
    char b[32] = ")({}(}{[";
    if (BracketChecker(a, 8))
        cout << "a-ok" << endl;
    if (BracketChecker(b, 8))
        cout << "b-ok" << endl;
    cout << "All-down!" << endl;
}