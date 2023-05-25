// Link : https://leetcode.com/problems/maximum-subarray/
// Time Complexity : O(n)
// Approach-> Kadane's Algo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Brute Force approach will be calculate all subarray and check its sum

// Applying Kadane's Algo...isme agar negative h localSum toh 0 lelo otherwise maxSum se jada h to update
int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        // MaxSum phle update kro before making zero kuuki phir bas ek element neg wala hoga to usse time
        // maxSum whi hona chahiye
        maxSum = max(sum, maxSum);
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}

int main()
{

    return 0;
}