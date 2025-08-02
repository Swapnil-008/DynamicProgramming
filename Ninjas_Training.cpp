#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ninjaTrainingHelper(int ind, int last, vector<vector<int>>& points, vector<vector<int>>& dp)
{
    if(ind == 0)
    {
        int maxi = 0;
        for(int i = 0; i < 3; i++)
        {
            if(i != last)
            {
                maxi = max(maxi, points[ind][i]);
            }
        }
        dp[ind][last] = maxi;
        return maxi;
    }
    if(dp[ind][last] != -1)
    {
        return dp[ind][last];
    }
    int maxi = 0;
    for(int i = 0; i < 3; i++)
    {
        if(i != last)
        {
            int temp = points[ind][i] + ninjaTrainingHelper(ind-1, i, points, dp);
            maxi = max(maxi, temp);
        }
    }
    dp[ind][last] = maxi;
    return maxi;
}

int ninjaTrainingMemoization(int n, vector<vector<int>>& points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return ninjaTrainingHelper(n-1, 3, points, dp);
}

int ninjaTrainingDp(int n, vector<vector<int>>& points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day < n; day++)
    {
        for(int last = 0; last < 4; last++)
        {
            int maxi = 0;
            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    int point = points[day][task] + dp[day-1][task];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }
    return dp[n-1][3];
}