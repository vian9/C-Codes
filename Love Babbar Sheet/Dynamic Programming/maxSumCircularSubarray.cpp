// Link : https://leetcode.com/problems/maximum-sum-circular-subarray/
// Time Complexity : O(n)
// Approach-> Phle maxSum and minSum dono nikal dia.....ab ek case toh Kadane's k jaisa beech k subarray ho toh thik h
// Otherwise total mein se minSum will give the other sum possible with start and end

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxSubarraySumCircular(vector<int> &nums)
{
    // will try to apply Modified kadane's
    int sum = 0;
    int maxSum = INT_MIN;
    int n = nums.size();
    int total = 0;
    int minSum = INT_MAX;
    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        diff += nums[i];
        total += nums[i];
        maxSum = max(sum, maxSum);
        minSum = min(minSum, diff);
        if (sum < 0)
            sum = 0;
        if (diff > 0)
            diff = 0;
    }
    int sum2 = total - minSum;
    // Agar pura element negative h to sum2 will give wrong ans and in that case maxSum is right ans toh wo return hoga
    if (maxSum > 0)
        return max(maxSum, sum2);
    return maxSum;
}

int main()
{

    return 0;
}