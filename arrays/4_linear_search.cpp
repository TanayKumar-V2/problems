#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(int);
    int key;
    ;
    cin >> key;

    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            ans = i;
            break;
        }
        else
        {
            ans = -1;
        }
    }
    cout << ans << endl;
    return 0;
}