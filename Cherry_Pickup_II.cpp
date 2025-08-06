#include <bits/stdc++.h>
using namespace std;

int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    return cherryPickupHelper(0, 0, n - 1, grid, dp);
}

int cherryPickupHelper(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size())
    {
        return -1e8;
    }
    if (i == grid.size() - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }
    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    int maxi = 0;
    for (int d1 = -1; d1 <= 1; d1++)
    {
        for (int d2 = -1; d2 <= 1; d2++)
        {
            int val = 0;
            if (j1 == j2)
            {
                val = grid[i][j1];
            }
            else
            {
                val = grid[i][j1] + grid[i][j2];
            }
            val += cherryPickupHelper(i + 1, j1 + d1, j2 + d2, grid, dp);
            maxi = max(maxi, val);
        }
    }
    dp[i][j1][j2] = maxi;
    return maxi;
}

//Less efficient than memoization
int cherryPickupDp(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
    for (int j1 = 0; j1 < n; j1++)
    {
        for (int j2 = 0; j2 < n; j2++)
        {
            if (j1 == j2)
            {
                dp[m - 1][j1][j2] = grid[m - 1][j1];
            }
            else
            {
                dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                int maxi = 0;
                for (int d1 = -1; d1 <= 1; d1++)
                {
                    for (int d2 = -1; d2 <= 1; d2++)
                    {
                        int nj1 = j1 + d1;
                        int nj2 = j2 + d2;
                        if (nj1 >= 0 && nj1 < n && nj2 >= 0 && nj2 < n)
                        {
                            int val = 0;
                            if (j1 == j2)
                            {
                                val = grid[i][j1];
                            }
                            else
                            {
                                val = grid[i][j1] + grid[i][j2];
                            }
                            val += dp[i + 1][nj1][nj2];
                            maxi = max(maxi, val);
                        }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][n - 1];
}