#include<bits/stdc++.h>
using namespace std;

int canPartitionHelper(vector<int>& nums, int ind, int target, vector<vector<int>>& dp)
{
    if(target == 0)
    {
        return 1;
    }
    if(ind == 0)
    {
        return nums[0] == target;
    }
    if(dp[ind][target] != -1)
    {
        return dp[ind][target];
    }
    int include = 0;
    if(nums[ind] <= target)
    {
        include = canPartitionHelper(nums, ind - 1, target - nums[ind], dp);
    }
    int exclude = canPartitionHelper(nums, ind - 1, target, dp);
    dp[ind][target] = include || exclude;
    return dp[ind][target];
}

bool canPartition(vector<int>& nums)
{
    int n = nums.size();
    int sum = 0;
    for(int &num : nums)
    {
        sum += num;
    }
    if(sum % 2 != 0)
    {
        return false;
    }
    int target = sum / 2;
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return canPartitionHelper(nums, n-1, target, dp);
}

bool canPartitionDp(vector<int>& nums)
{
    int n = nums.size();
    int sum = 0;
    for(int &num : nums)
    {
        sum += num;
    }
    if(sum % 2 != 0)
    {
        return false;
    }
    int target = sum / 2;
    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    for(int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if(nums[0] <= target)
    {
        dp[0][nums[0]] = 1;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= target; j++)
        {
            int include = 0;
            if(j >= nums[i])
            {
                include = dp[i-1][j-nums[i]];
            }
            int exclude = dp[i-1][j];
            dp[i][j] = include || exclude;
        }
    }
    return dp[n-1][target];
}