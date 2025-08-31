#include <iostream>
using namespace std;

int main()
{
    int n, d, reverse = 0;

    for (cin >> n; n > 0; n /= 10)
    {
        d = n % 10;
        reverse = reverse * 10 + d;
    }

    cout << reverse << endl;

    return 0;
}