#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsackHelper(int W, vector<int>& val, vector<int>& wt, int ind, vector<vector<int>>& dp)
{
    if(ind == 0)
    {
        return val[0] * (W / wt[0]);
    }
    if(dp[ind][W] != -1)
    {
        return dp[ind][W];
    }
    int include = INT_MIN;
    if(wt[ind] <= W)
    {
        include = val[ind] + unboundedKnapsackHelper(W - wt[ind], val, wt, ind, dp);
    }
    int exclude = unboundedKnapsackHelper(W, val, wt, ind + 1, dp);
    dp[ind][W] = max(include, exclude);
    return dp[ind][W];
}

int unboundedKnapsack(int W, vector<int>& val, vector<int>& wt)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return unboundedKnapsackHelper(W, val, wt, n-1, dp);
}

int unboundedKnapsackDp(int W, vector<int>& val, vector<int>& wt)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for(int i = 0; i <= W; i++)
    {
        dp[0][i] = val[0] * (i / wt[0]);
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            int include = 0;
            if(wt[i] <= j)
            {
                include = val[i] + dp[i][j - wt[i]];
            }
            int exclude = dp[i-1][j];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[n-1][W];
}