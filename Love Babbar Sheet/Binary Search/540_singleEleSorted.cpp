// Link : https://leetcode.com/problems/single-element-in-a-sorted-array/
// Time Complexity : O(logn) && Space : O(1)
// Approach-> Dekho....agar elements twice aarha...toh hmesa even nd then odd pos pr aarha hoga same wla...
// Ab agar check krke mid kisse match krrha h nd wo odd h ya even

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int searchHelper(vector<int> &nums, int low, int high)
{
    // Binary search tbtk chlega jbtk low < high
    if (low <= high)
    {
        int mid = (high - low) / 2 + low;
        // Edge cases with mid wla kisi se match nhi krrha h toh return it
        if ((mid == 0 && nums[mid] != nums[mid + 1]) || (mid == nums.size() - 1 && nums[mid] != nums[mid - 1]) || (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]))
        {
            return mid;
        }
        // Agar mid == mid+1...ab even h mid to aage wla m once wla aayega abhi tk nhi aaya h
        else if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1])
        {
            if (mid % 2 == 0)
            {
                return searchHelper(nums, mid + 1, high);
            }
            else
            {
                return searchHelper(nums, low, mid - 1);
            }
        }
        // if mid == mid-1 se match to even h mid toh phle once wla aagya h
        else if (mid > 0 && nums[mid] == nums[mid - 1])
        {
            if (mid % 2 == 0)
            {
                return searchHelper(nums, low, mid - 1);
            }
            else
            {
                return searchHelper(nums, mid + 1, high);
            }
        }
    }
    return low;
}
int singleNonDuplicate(vector<int> &nums)
{
    // Agar size 1 ho to directly element return krdo
    if (nums.size() == 1)
        return nums[0];
    return nums[searchHelper(nums, 0, nums.size() - 1)];
}

int main()
{

    return 0;
}