#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return cutRodHelper(n - 1, n, price, dp);
}

int cutRodHelper(int ind, int W, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return W * price[0];
    }
    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= W)
    {
        take = price[ind] + cutRodHelper(ind, W - rodLength, price, dp);
    }
    int notTake = cutRodHelper(ind - 1, W, price, dp);
    dp[ind][W] = max(take, notTake);
    return dp[ind][W];
}

int cutRodDp(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++)
    {
        dp[0][i] = price[0] * i;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int take = INT_MIN;
            int rodLength = i + 1;
            if (rodLength <= j)
            {
                take = price[i] + dp[i][j - rodLength];
            }
            int notTake = dp[i - 1][j];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n-1][n];
}