#include<iostream>
#include<vector>
using namespace std;

int fibonacciMemoization(vector<int> &nums, int ind)
{
    if(ind <= 1)
    {
        return ind;
    }
    if(nums[ind] == -1)
    {
        nums[ind] = fibonacciMemoization(nums, ind - 1) + fibonacciMemoization(nums, ind - 2);
    }
    return nums[ind];
}

int fibonacciDP(vector<int> &dp)
{
    for(int i = 2; i <= dp.size()-1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[dp.size()-1];
}

int main()
{
    int n;
    cout<<"Enter fibonacci number: ";
    cin>>n;
    vector<int> nums(n + 1, -1);
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    cout<<"Fibonacci number at position "<<n<<" is: "<<fibonacciMemoization(nums, n)<<endl;
    cout<<"Fibonacci number at position "<<n<<" is: "<<fibonacciDP(dp);
    return 0;
}