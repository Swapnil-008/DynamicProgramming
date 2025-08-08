#include <bits/stdc++.h>
using namespace std;

int minDifference(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
    {
        return arr[0];
    }
    int sum = 0;
    for (int &num : arr)
    {
        sum += num;
    }
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    for (int i = 0; i <= sum; i++)
    {
        minDifferenceHelper(n - 1, i, arr, dp);
    }
    int minDiff = INT_MAX;
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n - 1][i] == 1)
        {
            int s2 = sum - i;
            minDiff = min(minDiff, abs(s2 - i));
        }
    }
    return minDiff;
}
int minDifferenceHelper(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return nums[0] == sum;
    }
    if (dp[ind][sum] != -1)
    {
        return dp[ind][sum];
    }
    int include = 0;
    if (nums[ind] <= sum)
    {
        include = minDifferenceHelper(ind - 1, sum - nums[ind], nums, dp);
    }
    int exclude = minDifferenceHelper(ind - 1, sum, nums, dp);
    dp[ind][sum] = include || exclude;
    return dp[ind][sum];
}

int minDifferenceDp(vector<int>& arr)
{
    int n = arr.size();
    if (n == 1)
    {
        return arr[0];
    }
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n, vector<int>(sum+1, 0));
    dp[0][arr[0]] = 1;
    for(int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int include = 0;
            if(arr[i] <= j)
            {
                include = dp[i - 1][j - arr[i]];
            }
            int exclude = dp[i - 1][j];
            dp[i][j] = include || exclude;
        }
    }
    int minDiff = INT_MAX;
    for (int i = 0; i <= sum / 2; i++)
    {
        if(dp[n-1][i] == 1)
        {
            int s2 = sum - i;
            minDiff = min(minDiff, abs(i - s2));
        }
    }
    return minDiff;
}