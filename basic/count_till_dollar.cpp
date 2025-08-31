#include <iostream>
using namespace std;

int main()
{
    char ch;
    int cnt = 0;

    ch = cin.get();

    while (ch != '$')
    {

        cnt++;
        ch = cin.get();
    }

    cout << cnt;
    return 0;
}