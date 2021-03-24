#include "iostream"
using namespace std;

#define MAXLEN 255
typedef struct //定长
{
    char ch[MAXLEN];
    int length;
} SString;

typedef struct //动态
{
    char *h;
    int length;
} HString;
// HString S;
// S.ch = (char *)malloc(MAXLEN * sizeof(char));
// S.length = 0;

typedef struct StringNode //链式
{
    char ch;    //链式
    char ch[4]; //块链
    struct StringNode *next;
} StringNode, *String;

///////////////

// 求子串
bool SubString(SString &Sub, SString S, int pos, int len)
{
    if (pos + len - 1 > S.length)
        return false;
    for (int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];
    Sub.length = len;
    return true;
}

//比较，若S>T则返回值>0;若S=T，则返回值=0;若S<T，则返回值<0
int StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.length && i <= T.length; i++)
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    return S.length - T.length;
}

int Index0(SString S, SString T)
{
    int i = 1, n = S.length, m = T.length;
    SString sub;
    while (i <= n - m + 1)
    {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0)
            ++i;
        else
            return i;
    }
    return 0;
}

// 模式匹配
int Index(SString S, SString T)
{
    int k = 1;
    int i = k, j = 1;
    while (i < S.length && j < T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            k++;
            i = k;
            j = 1;
        }
    }
    if (j > T.length)
        return k;
    else
        return 0;
}

int Index_KMP0(SString S, SString T, int next[])
{
    int i = 1, j = 1;
    // int next[T.length+1];
    // get_next(T,next);
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

void get_next(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int Index_KMP(SString S, SString T)
{
    int i = 1, j = 1;
    // int next[T.length+1];
    int *next = new int[T.length + 1];
    get_next(T, next);
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    delete[] next;
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}