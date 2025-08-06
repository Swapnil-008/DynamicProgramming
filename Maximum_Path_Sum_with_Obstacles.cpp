#include <bits/stdc++.h>
using namespace std;

int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    if (grid[0][0] == -1)
    {
        return 0;
    }
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++)
    {
        if (grid[0][i] == -1)
        {
            break;
        }
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < m; i++)
    {
        if (grid[i][0] == -1)
        {
            break;
        }
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == -1)
            {
                continue;
            }
            if (dp[i - 1][j] != -1)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + grid[i][j]);
            }
            if (dp[i][j - 1] != -1)
            {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
    }
    return dp[m - 1][n - 1] == -1 ? 0 : dp[m - 1][n - 1];
}