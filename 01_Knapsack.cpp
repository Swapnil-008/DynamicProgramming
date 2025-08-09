#include <bits/stdc++.h>
using namespace std;

int knapsackHelper(vector<int> &weight, vector<int> &value, int maxWeight, int n, vector<vector<int>> &dp)
{
    if (n == 0 || maxWeight == 0)
    {
        return 0;
    }
    if (dp[n][maxWeight] != -1)
    {
        return dp[n][maxWeight];
    }
    int include = 0;
    if (weight[n - 1] <= maxWeight)
    {
        include = value[n - 1] + knapsackHelper(weight, value, maxWeight - weight[n - 1], n - 1, dp);
    }
    int exclude = knapsackHelper(weight, value, maxWeight, n - 1, dp);
    dp[n][maxWeight] = max(include, exclude);
    return dp[n][maxWeight];
}

int knapsack(vector<int> &weight, vector<int> &value, int maxWeight)
{
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1));
    return knapsackHelper(weight, value, maxWeight, n, dp);
}

int knapsackDp(vector<int> &weight, vector<int> &value, int maxWeight)
{
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            int include = 0;
            if (weight[i - 1] <= j)
            {
                include = value[i - 1] + dp[i - 1][j - weight[i - 1]];
            }
            int exclude = dp[i - 1][j];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[n][maxWeight];
}

int knapsackHelper2(vector<int> &weight, vector<int> &value, int maxWeight, int ind, vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        if(weight[0] <= maxWeight)
        {
            return value[0];
        }
        else{
            return 0;
        }
    }
    if (dp[ind][maxWeight] != -1)
    {
        return dp[ind][maxWeight];
    }
    int include = 0;
    if (weight[ind] <= maxWeight)
    {
        include = value[ind] + knapsackHelper(weight, value, maxWeight - weight[ind], ind - 1, dp);
    }
    int exclude = knapsackHelper(weight, value, maxWeight, ind-1, dp);
    dp[ind][maxWeight] = max(include, exclude);
    return dp[ind][maxWeight];
}

int knapsack2(vector<int> &weight, vector<int> &value, int maxWeight)
{
    int n = weight.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return knapsackHelper(weight, value, maxWeight, n-1, dp);
}