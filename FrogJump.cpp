#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& height)
    {
        int n = height.size();
        vector<int> vect(n);
        vect[0] = 0;
        vect[1] = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++)
        {
            int cost1 = vect[i-1] + abs(height[i] - height[i - 1]);
            int cost2 = vect[i-2] + abs(height[i] - height[i - 2]);
            vect[i] = min(cost1, cost2);
        }
        return vect[n-1];
    }
};