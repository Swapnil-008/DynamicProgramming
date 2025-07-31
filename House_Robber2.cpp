#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            return nums[0];
        }
        vector<int> temp1, temp2;
        for(int i = 0; i < n; i++)
        {
            if(i != n-1)
            {
                temp1.push_back(nums[i]);
            }
            if(i != 0)
            {
                temp2.push_back(nums[i]);
            }
        }
        int maxi1 = robHouseDP(temp1);
        int maxi2 = robHouseDP(temp2);
        return max(maxi1, maxi2);
    }
    int robHouseDP(vector<int>& temp)
    {
        int n = temp.size();
        vector<int> dp(n, 0);
        dp[0] = temp[0];
        for(int i = 1; i < n; i++)
        {
            int pick = temp[i];
            if(i > 1)
            {
                pick += dp[i-2];
            }
            int nonPick = dp[i-1];
            dp[i] = max(pick, nonPick);
        }
        return dp[n-1];
    }
};

