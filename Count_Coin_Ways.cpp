#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return changeHelper(coins, dp, n - 1, amount);
}

//Memoization gives TLE
int changeHelper(vector<int> &coins, vector<vector<int>> &dp, int ind, int amount)
{
    if (ind == 0)
    {
        if (amount % coins[0] == 0)
        {
            return 1;
        }
        return 0;
    }
    if (dp[ind][amount] != -1)
    {
        return dp[ind][amount];
    }
    int take = 0;
    if (coins[ind] <= amount)
    {
        take = changeHelper(coins, dp, ind, amount - coins[ind]);
    }
    int notTake = changeHelper(coins, dp, ind - 1, amount);
    return take + notTake;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            long long take = 0;
            if (coins[i] <= j)
            {
                take = dp[i][j - coins[i]];
            }
            long long notTake = dp[i - 1][j];
            if ((take + notTake) >= INT_MAX)
            {
                return 0;
            }
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][amount];
}