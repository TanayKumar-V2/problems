#include <iostream>
using namespace std;

int main()
{
    char ch;

    cin >> ch;

    int x = ch;
    if (x >= 65 and x <= 90)
    {
        cout << "Upper Case";
    }
    else
    {
        cout << "lower case";
    }

    return 0;
}