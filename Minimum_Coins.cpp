#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int> &coins, int sum)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    int res = minCoinsHelper(n-1, coins, sum, dp);
    if(res != INT_MAX)
    {
        return res;
    }
    return -1;
}

int minCoinsHelper(int ind, vector<int>& coins, int sum, vector<vector<int>>& dp)
{
    if(ind == 0)
    {
        if(sum % coins[0] == 0)
        {
            return (sum / coins[0]);
        }
        else{
            return INT_MAX;
        }
    }
    if(dp[ind][sum] != -1)
    {
        return dp[ind][sum];
    }
    int exclude = minCoinsHelper(ind-1, coins, sum, dp);
    int include = INT_MAX;
    if(coins[ind] <= sum)
    {
        int res =  minCoinsHelper(ind, coins, sum-coins[ind], dp);
        if(res != INT_MAX)
        {
            include = 1 + res;
        }
    }
    dp[ind][sum] = min(include, exclude);
    return dp[ind][sum];
}

int minCoinsDp(vector<int> &coins, int sum)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(sum+1, 0));
    for(int i = 0; i <= sum; i++)
    {
        if(i % coins[0] == 0)
        {
            dp[0][i] = i / coins[0];
        }
        else{
            dp[0][i] = INT_MAX;
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= sum; j++)
        {
            int exclude = dp[i-1][j];
            int include = INT_MAX;
            if(coins[i] <= j)
            {
                int res = dp[i][j - coins[i]];
                if(res != INT_MAX)
                {
                    include = 1 + res;
                }
            }
            dp[i][j] = min(include, exclude);
        }
    }
    if(dp[n-1][sum] != INT_MAX)
    {
        return dp[n-1][sum];
    }
    return -1;
}