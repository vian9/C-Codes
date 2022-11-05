// Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Time Complexity : O(logn)
// Approach-> Binary search lagana h aur bas cases dhyan rkhna h ki kahan pr kaun sa case lagrha h....jb mid rotated k
// hai ya nhi ye high aur low se detect kro

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Binary Search
// will return the element
int findMin(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
    {
        return nums[0];
    }
    if (nums[0] < nums[n - 1])
        return nums[0];
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        // Agar mid is the start of actual array...toh usse left and right dono mein bada hoga
        if (nums[mid] < nums[(mid + 1) % n] && nums[mid] < nums[(mid - 1) % n])
            return nums[mid];
        // agar mid high se chota h mtlb left mein jao...kuuki rotated part to high se bada hi hoga
        else if (nums[mid] < nums[high])
            high = mid;
        // agar mid low se bada h mtlb ki ye rotated part wla h toh right mein jana h
        else if (nums[mid] > nums[low])
            low = mid + 1;
        // low ko aage move krdo agar koi case nhi mila toh
        else
            low = mid + 1;
    }
    return nums[low];
}

int main()
{

    return 0;
}