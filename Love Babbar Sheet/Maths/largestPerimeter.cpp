// Link : https://leetcode.com/problems/largest-perimeter-triangle/
// Time Complexity : O(nlogn)
// Approach-> Just sort krdo and peeche se tart kro checking if third size is less than sum of 2 sides agar hua
// to whi hoga max perimeter

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int largestPerimeter(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.begin() + n);
    for (int i = nums.size() - 1; i > 1; i -)
    {
        if (nums[i] < nums[i - 1] + nums[i - 2])
        {
            return nums[i] + nums[i - 1] + nums[i - 2];
        }
    }
    return 0;
}

int main()
{

    return 0;
}