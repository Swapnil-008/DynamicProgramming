#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> &arr, int d)
{
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if ((totalSum - d) < 0 || (totalSum - d) % 2 != 0)
    {
        return 0;
    }
    int target = (totalSum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return countPartitionsHelper(n - 1, target, arr, dp);
}

int countPartitionsHelper(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && nums[0] == 0)
        {
            return 2;
        }
        if (target == 0 || nums[0] == target)
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
    if (nums[ind] <= target)
    {
        include = countPartitionsHelper(ind - 1, target - nums[ind], nums, dp);
    }
    int exclude = countPartitionsHelper(ind - 1, target, nums, dp);
    dp[ind][target] = include + exclude;
    return dp[ind][target];
}

int countPartitionsDp(vector<int> &arr, int d)
{
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if ((totalSum - d) < 0 || (totalSum - d) % 2 != 0)
    {
        return 0;
    }
    int target = (totalSum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    if(arr[0] == 0)
    {
        dp[0][0] = 2;
    }
    else{
        dp[0][0] = 1;
    }
    if (arr[0] != 0 && arr[0] <= target)
    {
        dp[0][arr[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int include = 0;
            if (arr[i] <= j)
            {
                include = dp[i-1][j - arr[i]];
            }
            int exclude = dp[i - 1][j];
            dp[i][j] = include + exclude;
        }
    }
    return dp[n-1][target];
}