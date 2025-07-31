#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Maximum Subarray Problem

//Brute force O(N^3)
int maximumSubarray1(vector<int>& nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    //Start of the subarray
    for(int i = 0; i < n; i++)
    {
        //End of the subarray
        for(int j = i; j < n; j++)
        {
            int sum = 0;
            //Taking sum of the subarray
            for(int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

//Better Approach O(N^2)
int maximumSubarray2(vector<int>& nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        //Taking sum of the subarray
        for(int j = i; j < n; j++)
        {
            sum += nums[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

//Optimal Approach O(N) Kadane's Algorithm
int maximumSubarray3(vector<int>& nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if(sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

//if they want subArray with maximum sum
vector<int> maximumSubarray4(vector<int>& nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0;
    int end = 0;
    int maxStart = 0;
    for(int i = 0; i < n; i++)
    {
        if(sum == 0)
        {
            start = i;
        }
        sum += nums[i];
        if(sum > maxi)
        {
            maxi = sum;
            maxStart = start;
            end = i;
        }
        if(sum < 0)
        {
            sum = 0;
        }
    }
    vector<int> subArray;
    for(int i = maxStart; i <= end; i++)
    {
        cout<<nums[i]<<" ";
        subArray.push_back(nums[i]);
    }
    return subArray;
}

int main()
{
    vector<int> nums{-2, -3, 4, -1, -2, 1, 5, 3};
    cout << maximumSubarray1(nums) << endl;
    cout << maximumSubarray2(nums) << endl;
    cout << maximumSubarray3(nums) << endl;
    maximumSubarray4(nums);
    return 0;
}