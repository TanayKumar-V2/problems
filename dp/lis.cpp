#include <iostream>
#include <climits>
using namespace std;

int lis(int *a, int n, int i, int *dp)
{
    if (i == n)
    {
        return;
    }
    int ans = 1;
    for (int j = i - 1; j >= 0; --j)
    {
    }
    dp[i] = ans;

    lis(a, n, i + 1, dp);
    return ans;
}

int main()
{
    int a[] = {10, 9, 3, 5, 4, 11, 7, 8};
    int n = sizeof(a) / sizeof(int);

    int dp[100];

    lis(a, n, 0, dp);

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    return 0;
}