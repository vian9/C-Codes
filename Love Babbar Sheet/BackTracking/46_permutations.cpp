// Link : https://leetcode.com/problems/permutations/
// Time Complexity : O(2^n )
// Approach-> Phle pick kia in iterate nd mark krdia ki pick kia h nd then don't pick

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// M-1 will use swap instead of freq
void recurse(int ind, vector<vector<int>> &ans, vector<int> &nums)
{
    // Jb size equal ho jaye to push
    if (ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    // Thora complex than pick unpick....isme hum loop se start item lerhe nd usse swap krrhe
    // aur ab woh ind k next wale pr call krrhe
    for (int i = ind; i < nums.size(); i++)
    {
        swap(nums[ind], nums[i]);
        recurse(ind + 1, ans, nums);
        swap(nums[ind], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    recurse(0, ans, nums);
    return ans;
}

// M-2 taaki a lot more space
void recurse(int n, vector<vector<int>> &ans, vector<int> &nums, vector<int> &freq, vector<int> &ds)
{
    // Jb size equal ho jaye to push
    if (ds.size() == n)
    {
        ans.push_back(ds);
        return;
    }

    // Loop mein call krrhe
    for (int i = 0; i < n; i++)
    {
        if (freq[i] == 0)
        {
            // Push kia toh pick
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurse(n, ans, nums, freq, ds);
            // Not pick
            ds.pop_back();
            freq[i] = 0;
            // Iske baad don't call as woh loop hai hi it will iterate
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> freq(nums.size(), 0);
    vector<int> ds;
    recurse(nums.size(), ans, nums, freq, ds);
    return ans;
}

int main()
{

    return 0;
}