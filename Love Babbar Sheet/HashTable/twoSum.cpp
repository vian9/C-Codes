// Link : https://leetcode.com/problems/two-sum/
// Time Complexity : O(n)
// Approach-> Map lelia and usme index daal dia.....ab phir se loop iterate kia and agar

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); i++)
    {
        freq.insert({nums[i], i});
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = (target - nums[i]);
        if (freq.count(diff) > 0)
            if (freq[diff] != i)
            {
                ans.push_back(i);
                ans.push_back(freq[diff]);
                break;
            }
    }
    return ans;
}

int main()
{

    return 0;
}