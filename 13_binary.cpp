#include <iostream>
#include<climits>
using namespace std;

int main()
{
    int n = INT_MAX;
    int i = 30;

    while (i >= 0)
    {
        if ((n & (1 << i)) > 0)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }

        i--;
    }

    cout << endl;

    return 0;
}