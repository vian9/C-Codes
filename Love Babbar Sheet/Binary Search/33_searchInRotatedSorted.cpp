// Link : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Time Complexity : O(logn)
// Approach-> Position jahan se array rotate hua nikalo and ab 2 subarrays mein binary search lagado

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int search(vector<int> &nums, int target)
{
    int pos = -1;
    int n = nums.size();
    int low = 0, high = n - 1;
    if (n <= 1)
    {
        if (nums[0] == target)
            return 0;
        else
            return -1;
    }
    int low = 0, high = n - 1;
    // If array is not sorted
    if (nums[0] > nums[n - 1])
    {
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            // Agar mid is the start of actual array...toh usse left and right dono mein bada hoga
            if (nums[mid] < nums[(mid + 1) % n] && nums[mid] < nums[(mid - 1) % n])
            {
                pos = mid;
                break;
            }
            // agar mid high se chota h mtlb left mein jao...kuuki rotated part to high se bada hi hoga
            else if (nums[mid] < nums[high])
                high = mid;
            // agar mid low se bada h mtlb ki ye rotated part wla h toh right mein jana h
            else if (nums[mid] > nums[low])
                low = mid + 1;
            // low ko aage move krdo agar koi case nhi mila toh
            else
                low = mid + 1;
            pos = low;
        }
        // Ab 2 subarrays mein lower bound lagakr check krenge kisme hai
        vector<int>::iterator pos1 = lower_bound(nums.begin(), nums.begin() + pos - 1, target);
        vector<int>::iterator pos2 = lower_bound(nums.begin() + pos, nums.end(), target);
        // iterator se pos nikalne k liye begin k address se subtract
        int ps1 = pos1 - nums.begin();
        int ps2 = pos2 - nums.begin(); // Ye bhi pura array mein se position dega kuuki iterator use kia tha with maybe diff start pos
        // Agar ps1 and ps2 sahi h aur target se match to return
        if ((ps1 >= 0 && ps1 < pos) && nums[ps1] == target)
            return ps1;
        if ((ps2 >= pos && ps2 < n) && nums[ps2] == target)
            return ps2;
    }
    else
    {
        // If array is sorted to directly lagao lower bound and check
        vector<int>::iterator pss1 = lower_bound(nums.begin(), nums.end(), target);
        int pos1 = pss1 - nums.begin();
        if ((pos1 >= 0 && pos1 < n) && nums[pos1] == target)
            return pos1;
    }
    return -1;
}

int main()
{

    return 0;
}