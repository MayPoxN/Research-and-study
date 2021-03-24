#include "iostream"
using namespace std;

// 算法1——逐步递增型爱你
void loveYou1(int n) // n 为问题规模
{
    int i = 1; // 爱你的程度
    while (i <= n)
    {
        i++; // 每次+1
        cout << "I love you " << i << endl;
    }
    cout << "I love you More than " << i << endl;
}

// 算法2——嵌套循环型爱你
void loveYou2(int n) // n 为问题规模
{
    int i = 1; // 爱你的程度
    while (i <= n)
    {
        i++; // 每次+1
        cout << "I love you " << i << endl;
        for (int j = 1; j <= n; j++)
        {
            /* code */
            cout << "I am Iron Man" << endl;
        }
    }
    cout << "I love you More than " << i << endl;
}

// 算法3——指数递增型爱你
void loveYou3(int n) // n 为问题规模
{
    int i = 1;
    while (i <= n)
    {
        i = i * 2;
        cout << "I love you " << i << endl;
    }
    cout << "I love you More than " << i << endl;
}

// 算法4——搜索数字型爱你
void loveYou4(int flag[], int n) // n 为问题规模
{
    cout << "I am Iron Man" << endl;
    for (int i = 0; i < n; i++)
        if (flag[i] == n)
        {
            cout << "I love you " << i << endl;
            break;
        }
}

// 算法5——递归型爱你
void loveYou5(int n) // n 为问题规模
{
    int a, b, c;
    if (n > 1)
        loveYou5(n - 1);
    cout << "I love you " << n << endl;
}

int main(int argc, char **argv)
{
    int a = 0;
    cin >> a;
    // int flag[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // loveYou4(flag, a);
    loveYou5(a);
}