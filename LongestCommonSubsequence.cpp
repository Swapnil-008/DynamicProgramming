#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return longestCommonSubsequenceHelper(n - 1, m - 1, text1, text2, dp);
}

int longestCommonSubsequenceHelper(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }
    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    if (text1[ind1] == text2[ind2])
    {
        dp[ind1][ind2] = 1 + longestCommonSubsequenceHelper(ind1 - 1, ind2 - 1, text1, text2, dp);
        return dp[ind1][ind2];
    }
    dp[ind1][ind2] = max(longestCommonSubsequenceHelper(ind1 - 1, ind2, text1, text2, dp), longestCommonSubsequenceHelper(ind1, ind2 - 1, text1, text2, dp));
    return dp[ind1][ind2];
}

int longestCommonSubsequenceDp(string text1, string text2)
{
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        if (text1[i] == text2[0])
        {
            dp[i][0] = 1;
        }
        else if (i > 0)
        {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (text1[0] == text2[i])
        {
            dp[0][i] = 1;
        }
        else if (i > 0)
        {
            dp[0][i] = dp[0][i - 1];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (text1[i] == text2[j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n - 1][m - 1];

    // Alternative  // now the index 0 is dp[1][i] and index -1 is dp[0][i]  /just shift the index right by 1
    // int n = text1.length();
    // int m = text2.length();
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (text1[i - 1] == text2[j - 1])
    //         {
    //             dp[i][j] = 1 + dp[i - 1][j - 1];
    //         }
    //         else
    //         {
    //             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //         }
    //     }
    // }
    // return dp[n][m];
}