#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstringHelper(int m, int n, int &maxi, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    if (s1[m - 1] == s2[n - 1])
    {
        int res = longestCommonSubstringHelper(m - 1, n - 1, maxi, s1, s2, dp);
        dp[m][n] = 1 + res;
        maxi = max(maxi, dp[m][n]);
    }
    else
    {
        dp[m][n] = 0;
    }
    longestCommonSubstringHelper(m - 1, n, maxi, s1, s2, dp);
    longestCommonSubstringHelper(m, n - 1, maxi, s1, s2, dp);
    return dp[m][n];
}

int longestCommonSubstring(string &s1, string &s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int maxi = 0;
    longestCommonSubstringHelper(m, n, maxi, s1, s2, dp);
    return maxi;
}

int longestCommonSubstringDp(string &s1, string &s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    int maxi = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
            maxi = max(maxi, dp[i][j]);
        }
    }
    return maxi;
}