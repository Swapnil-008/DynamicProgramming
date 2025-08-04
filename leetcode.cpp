#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight)
    {
        int n = weight.size();
        int left = 0, right = 0;
        int count = 0;
        int maxi = 0;
        while(right < n)
        {
            maxi = max(maxi, weight[right]);
            if(weight[right] < maxi)
            {
                count++;
                maxi = 0;
            }
            right++;
        }
        return count;
    }
};

class Solution {
public:
    int minTime(string s, vector<int>& order, int k)
    {
        for(int i = 0; i < s.length(); i++)
        {
            s[order[i]] = '*';
            if(validSubstrings(s) > k)
            {
                return i;
            }
        }
        return -1;
    }
    int validSubstrings(string &str)
    {
        vector<string> vect;
        for(int i = 0; i < str.length(); i++)
        {
            for(int j = 0; j < str.length(); j++)
            {
                string s = s.substr(i, j+1);
                vect.push_back(s);
            }
        }
        int count = 0;
        for(int i = 0; i < vect.size(); i++)
        {
            if(vect[i].find('*') != -1)
            {
                count++;
            }
        }
        return count;
    }
};