#include<bits/stdc++.h>
using namespace std;

int uniquePathsRecursive(int m, int n)
{
    if(m == 0 && n == 0)
    {
        return 1;
    }
    if(m < 0 || n < 0)
    {
        return 0;
    }
    int up = uniquePathsRecursive(m-1, n);
    int left = uniquePathsRecursive(m, n-1);
    return up + left;
}

int uniquePathsMemoization(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePathsMemoizationHelper(m-1, n-1, dp);
}

int uniquePathsMemoizationHelper(int m, int n, vector<vector<int>>& dp)
{
    if(m == 0 && n == 0)
    {
        return 1;
    }
    if(m < 0 || n < 0)
    {
        return 0;
    }
    if(dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int up = uniquePathsMemoizationHelper(m-1, n, dp);
    int left = uniquePathsMemoizationHelper(m, n-1, dp);
    dp[m][n] = up + left;
    return dp[m][n];
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else{
                int up = (i > 0) ? dp[i-1][j] : 0;
                int left = (j > 0) ? dp[i][j-1] : 0;
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}

int uniquePathsWithObstaclesDp(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
    {
        return 0;
    }
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int j = 0; j < n; j++)
    {
        if (obstacleGrid[0][j] == 1)
        {
            break;
        }
        dp[0][j] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        if (obstacleGrid[i][0] == 1)
        {
            break;
        }
        dp[i][0] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = uniquePathsWithObstaclesHelper(m - 1, n - 1, obstacleGrid, dp);
    return ans;
}
int uniquePathsWithObstaclesHelper(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
    {
        return grid[0][0] == 0 ? 1 : 0;
    }
    if (m < 0 || n < 0 || grid[m][n] == 1)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int up = uniquePathsWithObstaclesHelper(m - 1, n, grid, dp);
    int left = uniquePathsWithObstaclesHelper(m, n - 1, grid, dp);
    dp[m][n] = up + left;
    return dp[m][n];
}