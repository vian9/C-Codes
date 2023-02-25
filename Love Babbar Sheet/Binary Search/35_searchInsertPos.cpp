// Link : https://leetcode.com/problems/search-insert-position/
// Time Complexity : O(logn)
// Approach-> Low High pass krdiya and call krrhe as binary search...bs when low > high ho jaye to low wale position
// pr insert krenge

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