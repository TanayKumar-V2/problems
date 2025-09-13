#include <iostream>
using namespace std;

int main()
{
    char a[100];
    cin.getline(a, 100);

    int cnt = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        cnt++;
    }

    cout << cnt << endl;

    cout << a << endl;
    return 0;
}