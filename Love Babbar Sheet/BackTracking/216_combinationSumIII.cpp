// Link : https://leetcode.com/problems/combination-sum-iii/
// Time Complexity : O()
// Approach-> Same as Combination Sum II bs yha ye kia ki 1 to 9 k vector lelia

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void myCombo(vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums, int k, int n, int ind)
{
    int m = ds.size();
    if (ind >= 9)
    {
        // Ab agar size k ke barabar and sum 0 tb push krdo
        if (m == k && n == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (m == k)
    {
        if (n == 0)
            ans.push_back(ds);
        return;
    }

    // Phla kaun select hoga wo dekhlo and kuuki sb unique h to continue k jrurt nhi
    for (int i = ind; i < 9; i++)
    {
        ds.push_back(nums[i]);
        myCombo(ans, ds, nums, k, n - nums[i], i + 1);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    // 1 to 9 at most once should be used
    vector<int> nums;
    for (int i = 0; i < 9; i++)
    {
        nums.push_back(i + 1);
    }
    vector<vector<int>> ans;
    vector<int> ds;
    myCombo(ans, ds, nums, k, n, 0);
    return ans;
}

int main()
{

    return 0;
}