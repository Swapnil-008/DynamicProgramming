#include <bits/stdc++.h>
using namespace std;

int perfectSum(vector<int> &arr, int target)
{
    int n = arr.size();
    if (n == 1 && arr[0] == target)
    {
        return 1;
    }
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return perfectSumHelper(n - 1, target, arr, dp);
}
int perfectSumHelper(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
        {
            return 2;
        }
        if (target == 0 || arr[0] == target)
        {
            return 1;
        }
        return 0;
    }
    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }
    int include = 0;
    if (arr[ind] <= target)
    {
        include = perfectSumHelper(ind - 1, target - arr[ind], arr, dp);
    }
    int exclude = perfectSumHelper(ind - 1, target, arr, dp);
    return include + exclude;
}

int perfectSumDp(vector<int>& arr, int target)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    dp[0][0] = (arr[0] == 0) ? 2 : 1;
    if (arr[0] != 0 && arr[0] <= sum)
    {
        dp[0][arr[0]] = 1;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= sum; j++)
        {
            int include = 0;
            if (arr[i] <= j)
            {
                include = dp[i - 1][j - arr[i]];
            }
            int exclude = dp[i - 1][j];
            dp[i][j] = include + exclude;
        }
    }
    return dp[n-1][target];
}