#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int solve(string &s1, string &s2, int n, int m, int dp[][100])
{
    if (n == 0 or m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = 1 + solve(s1, s2, n - 1, m - 1, dp);
    }
    else
    {
        return dp[n][m] = max(solve(s1, s2, n - 1, m, dp), solve(s1, s2, n, m - 1, dp));
    }
}

int bottom_up(string &s1, string &s2, int dp[][100])
{
    int s1_len = s1.size();
    int s2_len = s2.size();

    for (int i = 1; i <= s1_len; i++)
    {
        for (int j = 1; j <= s2_len; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[s1_len][s2_len];
}

void printLCS(string &s1, string &s2, int m, int n, int dp[][100], string op = "")
{
    if (n == 0 and m == 0)
    {
        reverse(op.begin(), op.end());
        cout << op << " ";
        return;
    }

    if (s1[n - 1] == s2[m - 1])
    {
        printLCS(s1, s2, n - 1, m - 1, dp, op + s1[n - 1]);
    }
    else
    {
        if (dp[n][m] == dp[n - 1][m])
        {
            printLCS(s1, s2, n - 1, m, dp, op);
        }
        if (dp[n][m] == dp[n][m - 1])
        {
            printLCS(s1, s2, n, m - 1, dp, op);
        }
    }
}

int main()
{
    int dp[100][100];
    memset(dp, -1, sizeof(dp));
    string s1 = "abcde";
    string s2 = "acbde";

    cout << "Top-down result: " << solve(s1, s2, s1.size(), s2.size(), dp) << endl;
    
    int dp2[100][100] = {};
    cout << "Bottom-up result: " << bottom_up(s1, s2, dp2) << endl;
    
    cout << "All LCS: ";
    printLCS(s1, s2, s1.size(), s2.size(), dp2);
    cout << endl;

    return 0;
}
