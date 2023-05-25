// Link : https://leetcode.com/problems/binary-search/
// Time Complexity : O()
// Approach-> Binary search lga lo divide and conquer

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int search(vector<int> &nums, int target)
{
    int high = nums.size() - 1, low = 0;
    // iterative approach
    // high low jbtk alag h tbtk
    while (low < high)
    {
        int mid = (high - low) / 2 + low;
        if (nums[mid] == target)
        {
            return mid;
        }
        // equality bs mid se equal m
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    // ab 1 size ya koi case m loop over and check value matches
    if (nums[low] != target)
        return -1;
    return low;
}

int main()
{

    return 0;
}