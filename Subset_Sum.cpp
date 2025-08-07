#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return isSubsetSumHelper(n - 1, sum, arr, dp);
}

int isSubsetSumHelper(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        return sum == nums[ind];
    }
    if (dp[ind][sum] != -1)
    {
        return dp[ind][sum];
    }
    int include = 0;
    if (nums[ind] <= sum)
    {
        include = isSubsetSumHelper(ind - 1, sum - nums[ind], nums, dp);
    }
    int exclude = isSubsetSumHelper(ind - 1, sum, nums, dp);
    dp[ind][sum] = include || exclude;
    return dp[ind][sum];
}
bool isSubsetSumDp(vector<int> &arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= sum)
    {
        dp[0][arr[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            int include = 0;
            if (arr[i] <= j)
            {
                include = dp[i - 1][j - arr[i]];
            }
            int exclude = dp[i - 1][j];
            dp[i][j] = include | exclude;
        }
    }
    return dp[n - 1][sum];
}