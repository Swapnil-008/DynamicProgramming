#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int minSum = INT_MAX;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        int ans = minFallingPathSumHelper(m - 1, i, matrix, dp);
        minSum = min(minSum, ans);
    }
    return minSum;
}
int minFallingPathSumHelper(int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (n < 0 || n >= matrix[0].size())
    {
        return INT_MAX;
    }
    if (m == 0)
    {
        return matrix[m][n];
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int left = minFallingPathSumHelper(m - 1, n - 1, matrix, dp);
    int up = minFallingPathSumHelper(m - 1, n, matrix, dp);
    int right = minFallingPathSumHelper(m - 1, n + 1, matrix, dp);
    return dp[m][n] = matrix[m][n] + min({left, up, right});
}

int minFallingPathSumDp(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = matrix[0][i];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
            int up = dp[i - 1][j];
            int right = (j < n - 1) ? dp[i - 1][j + 1] : INT_MAX;
            dp[i][j] = min({left, up, right}) + matrix[i][j];
        }
    }
    int minSum = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        minSum = min(minSum, dp[m - 1][j]);
    }
    return minSum;
}