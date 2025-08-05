#include <bits/stdc++.h>
using namespace std;

int minimumTotalDp(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp;
    for (int i = 1; i <= m; i++)
    {
        vector<int> temp(i, 0);
        dp.push_back(temp);
    }
    for(int i = 0; i < n; i++)
    {
        dp[n-1][i] = triangle[n-1][i];
    }
    for(int i = m-2; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
        {
            dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
        }
    }
    return dp[0][0];
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp;
    for (int i = 1; i <= m; i++)
    {
        vector<int> temp(i, -1);
        dp.push_back(temp);
    }
    return minimumTotalHelper(0, 0, triangle, dp);
}

int minimumTotalHelper(int m, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (m == triangle.size() - 1)
    {
        return triangle[m][n];
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int down = minimumTotalHelper(m + 1, n, triangle, dp);
    int right = minimumTotalHelper(m + 1, n + 1, triangle, dp);
    return min(down, right) + triangle[m][n];
}