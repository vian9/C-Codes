// Link : https://leetcode.com/problems/majority-element-ii/submissions/
// Time Complexity : O(n) and Space : O(1)
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space O(1) ....Boyce Moore Voting ALgo
vector<int> majorityElement(vector<int> &nums)
{
    // 2 se jda nhi ho skta....as n/3 se bda
    int nums1 = INT_MIN, nums2 = INT_MAX;
    int count1 = 0, count2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // Agar kisi ka count 0 to candidate change krdo
        if (nums1 == nums[i])
        {
            count1++;
        }
        else if (nums2 == nums[i])
        {
            count2++;
        }
        else if (count1 == 0)
        {
            nums1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            nums2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    // Ab jo 2 nums aaye unke freq check krlo agar n/3 se jda to ans
    vector<int> ans;
    count1 = 0, count2 = 0;
    for (auto num : nums)
    {
        if (nums1 == num)
        {
            count1++;
        }
        else if (nums2 == num)
        {
            count2++;
        }
    }
    if (count1 > nums.size() / 3)
    {
        ans.push_back(nums1);
    }
    if (count2 > nums.size() / 3)
    {
        ans.push_back(nums2);
    }
    return ans;
}

// Brute force is hash map m daldo Space : O(n)
vector<int> majorityElement(vector<int> &nums)
{
    // Brute force is hashmap
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    vector<int> ans;
    for (auto num : mp)
    {
        if (num.second > nums.size() / 3)
        {
            ans.push_back(num.first);
        }
    }
    return ans;
}

int main()
{

    return 0;
}