#include <stdio.h>

void test(int &x)
{
    x = 1024;
    printf("inside function test x=%d\n", x);
}

int main(int argc, char **argv)
{
    int x = 1;
    printf("before test x=%d\n", x);
    test(x);
    printf("after test x=%d\n", x);
}