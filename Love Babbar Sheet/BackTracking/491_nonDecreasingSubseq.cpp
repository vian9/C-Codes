// Link : https://leetcode.com/problems/non-decreasing-subsequences/
// Time Complexity : O(2^n)
// Approach-> Hume non-decreasing order mein chahiye nd repeats ho skte h
// toh simply pick if it;s bigger than the last item nd non-pick
// set lelo to avoid duplicate vectors

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void subsequence(int ind, int n, vector<int> &nums, vector<int> &ds, set<vector<int>> &ans)
{
    if (ind == n)
    {
        if (ds.size() >= 2)
        {
            ans.insert(ds);
        }
        return;
    }

    // Agar set size 0 ho ya item bada ho to pick
    if ((ds.size() == 0) || (ds[ds.size() - 1] <= nums[ind]))
    {
        ds.push_back(nums[ind]);
        subsequence(ind + 1, n, nums, ds, ans);
        // // Non-pick
        ds.pop_back();
    }
    // otherwise don't pick
    subsequence(ind + 1, n, nums, ds, ans);
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<int> ds;
    // set lia taaki items repeat na kre
    set<vector<int>> ans;
    subsequence(0, nums.size(), nums, ds, ans);
    // ab wo set ko vector mein daldo
    return vector(ans.begin(), ans.end());
}

int main()
{

    return 0;
}