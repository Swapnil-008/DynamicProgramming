#include <iostream>
#include <vector>
using namespace std;

int findMaxSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}

int recursive(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
    {
        return nums[0];
    }
    if (ind < 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int pick = nums[ind] + recursive(ind - 2, nums, dp);
    int notPick = recursive(ind - 1, nums, dp);
    dp[ind] = max(pick, notPick);
    return dp[ind];
}