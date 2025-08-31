#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int no;
    int ans = 0;

    int i = 1;
    while (i <= n)
    {
        cin >> no;

        ans = ans ^ no;

        i++;
    }

    cout << "Answer is : " << ans << endl;

    return 0;
}