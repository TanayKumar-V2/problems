#include <iostream>
using namespace std;

int main()
{
    int r, no, n;
    cin >> n;

    for (r = 1; r <= n; r++)
    {
        no = r % 2;

        for (int i = 1; i <= r; i++)
        {
            cout << no << " ";
            no = 1 - no;
        }
        cout << endl;
    }

    return 0;
}