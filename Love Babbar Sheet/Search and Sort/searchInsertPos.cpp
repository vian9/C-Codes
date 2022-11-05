// Link : https://leetcode.com/problems/search-insert-position/
// Time Complexity : O(logn)
// Approach-> Binary search is agar target milgya to thik otherwise low ko return kro.....as low > high pr condition tutega
// And low will give the position jahan rehna chahiye tha

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int targetPos(vector<int> &nums, int target, int low, int high)
{

    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            return targetPos(nums, target, low, mid - 1);
        }
        else
        {
            return targetPos(nums, target, mid + 1, high);
        }
    }
    return low;
}

int searchInsert(vector<int> &nums, int target)
{
    return targetPos(nums, target, 0, nums.size() - 1);
}

int main()
{

    return 0;
}