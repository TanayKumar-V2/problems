#include <iostream>
using namespace std;

int main()
{
    int ini, f, step;
    cin >> ini >> f >> step;

    int i = ini;

    while (i <= f)
    {
        cout << i << " : " << ((5 / 9.0) * (i - 32));
        i = i + step;
        cout << endl;
    }

    return 0;
}