// Link : https://leetcode.com/problems/minimize-maximum-of-array/
// Time Complexity : O()
// Approach-> Binary search lga skte ho between values 0 and max val in array and check condition satisfies ki
// prefixx sum < x * i+1 se
// Greedy approach is at any point sum is equally divided with all components....to uske liye divide krdo and keep ceil val

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minimizeArrayValue(vector<int> &nums)
{
    // Brute force - harr pr jao and jo sum ho uska ceil value lo and distribute krdo
    long long minVal = 0;
    long long prefixSum = 0;
    // At any point for maxVal * (i+1) can't be less than prefix Sum as x is the max number
    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        minVal = max((prefixSum + i) / (i + 1), minVal);
    }
    return minVal;
}

int main()
{

    return 0;
}