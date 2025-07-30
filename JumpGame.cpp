#include <iostream>
#include <vector>
using namespace std;

bool canJumpGreedy(vector<int> &nums)
{
    int n = nums.size();
    int maxi = nums[0];
    for (int i = 0; i <= maxi; i++)
    {
        maxi = max(maxi, i + nums[i]);
        if (maxi >= n - 1)
        {
            return true;
        }
    }
    return false;
}

bool canJumpDP(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        if (!dp[i])
        {
            continue;
        }
        for (int j = 1; j <= nums[i] && i + j < n; j++)
        {
            dp[i + j] = true;
        }
    }
    return dp[n - 1];
}
