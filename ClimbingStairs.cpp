#include <iostream>
#include <vector>
using namespace std;

int climbStairsDP(int n)
{
    if (n <= 2)
    {
        return n;
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int climbStairsMemoization(vector<int> &nums, int ind)
{
    if(ind <= 2)
    {
        return ind;
    }
    if(nums[ind] == -1)
    {
        nums[ind] = climbStairsMemoization(nums, ind-1) + climbStairsMemoization(nums, ind-2);
    }
    return nums[ind];
}

int climbStairsIterative(int n)
{
    if (n <= 2)
    {
        return n;
    }
    int prev = 1;
    int curr = 2;
    int ans = 0;
    for(int i = 3; i <= n; i++)
    {
        ans = prev + curr;
        prev = curr;
        curr = ans;
    }
    return ans;
}