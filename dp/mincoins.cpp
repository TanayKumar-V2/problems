#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int bottomUp(int amount, int *deno, int n)
{
    int dp[10000];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        int ans = INT_MAX;
        for (int k = 0; k < n; k++)
        {
            if (i >= deno[k])
            {
                int ci = i - deno[k];
                if (dp[ci] != INT_MAX)
                {
                    ans = min(ans, dp[ci]);
                }
            }
        }

        dp[i] = ans;
    }

    return dp[amount];
}

int main()
{
    int deno[] = {2, 7, 10};
    int n = sizeof(deno) / sizeof(int);
    int amount = 35;
    vector<int> dp(amount + 1, -1);
    cout << bottomUp(amount, deno, n);
}