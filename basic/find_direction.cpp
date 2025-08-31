#include <iostream>
using namespace std;

int main()
{

    char ch;

    ch = cin.get();

    int x = 0, y = 0;

    while (ch != '\n')
    {
        if (ch == 'S')
            y--;
        else if (ch == 'N')
            y++;
        else if (ch == 'E')
            x++;
        else
            x--;

        ch = cin.get();
    }

    if (x >= 0)
    {
        for (int i = 0; i < x; i++)
        {
            cout << "E";
        }
    }

    char temp;

    if (y >= 0)
        temp = 'N';
    else
        temp = 'S';

    y = abs(y);
    for (int i = 0; i < y; i++)
    {
        cout << temp;
    }

    if (x <= 0)
    {
        x = abs(x);
        for (int i = 0; i < x; i++)
        {
            cout << 'W';
        }
    }

    cout << endl;

    return 0;
}