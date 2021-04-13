#include <iostream>
#include "conio.h"
using namespace std;

int main()
{
    char ch;
    while (true)
    {
        cout << "Please enter a key: " << endl;
        ch = getch();
        if (ch == 'q') return 0;
        cout << "The key you have enter is ->" << ch << "\n\r";
    }

    return 0;
}
