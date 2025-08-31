#include <iostream>
using namespace std;

int main()
{
    int a[100];
    int n ; cin>>n;
 
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}