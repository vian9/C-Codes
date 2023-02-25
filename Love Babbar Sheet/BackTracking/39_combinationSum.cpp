// Link : https://leetcode.com/problems/combination-sum/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void combination(vector<int> &candidates, int target, int ind, vector<vector<int>> &ans, vector<int> &ds)
{
    int n = candidates.size();
    if (ind == n)
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    ds.push_back(candidates[ind]);
    combination(candidates, target - candidates[ind], ind, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    // hum kitna baar bhi choose kr skte h
    //  toh ek baar choose pick kro nd not pick kro
    vector<vector<int>> ans;
    vector<int> ds;
}

int main()
{

    return 0;
}