// Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int removeDuplicates(vector<int> &nums)
{
    // jo brute force aarha h swap kro
    // let's first do with extra space
    vector<int> nums2(-1, nums.size());
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int val = nums[i];
        int j = i + 1;
        while (nums[j] == val)
        {
            j++;
        }
        nums2[count] = val;
        while (j > 0)
        {
            nums2[nums.size() - count - j] = val;
            j--;
        }
        count++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums2[i];
    }
    return count;
}

int main()
{

    return 0;
}