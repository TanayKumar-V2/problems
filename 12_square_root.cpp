#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    float ans = 0;
    float inc = 1;

    int cp = 1;

    while (cp <= 5)
    {
        while (ans * ans <= n)
        {
            ans = ans + inc;
        }
        ans = ans - inc;

        cp = cp + 1;
        inc = inc / 10;
    }

    cout << ans << endl;

    return 0;
}