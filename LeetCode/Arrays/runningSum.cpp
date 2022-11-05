// Link : https://leetcode.com/problems/running-sum-of-1d-array/
// Time Complexity : O(n)
// Approach-> Sum mein add krte gye and push krdia vector mein

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> runningSum(vector<int> &nums)
{
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        ans.push_back(sum);
    }
    return ans;
}

int main()
{

    return 0;
}