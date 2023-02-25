// Link : https://leetcode.com/problems/shuffle-the-array/
// Time Complexity : O(n)
// Approach-> 2 Pointer approach se lete jao vector mein and iterate it

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> shuffle(vector<int> &nums, int n)
{
    int i = 0;
    int j = n;
    vector<int> ans(nums.size());
    int k = 0;
    while (i < n && j < 2 * n)
    {
        ans[k] = nums[i];
        ans[k + 1] = nums[j];
        i++;
        j++;
        k += 2;
    }
    return ans;
}

int main()
{

    return 0;
}