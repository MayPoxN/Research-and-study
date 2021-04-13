#include "iostream"
using namespace std;

#define MAX_SIZE 10
#define ElemType int

typedef struct Linknode
{
    ElemType data;
    struct Linknode *next;
} * LiStack;
// 链栈，栈顶是头部指针，头插法