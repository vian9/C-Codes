// Link : https://leetcode.com/problems/combination-sum/
// Time Complexity : O(2^t * k)
// Approach-> Phle ko select kro....phir se usse index ko call krdo & ek ko next index ko call krdo without pick

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void combination(vector<int> &candidates, int target, int ind, vector<vector<int>> &ans, vector<int> &ds)
{
    int n = candidates.size();
    if (ind >= n)
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

    // pick kro push krke nd call itself...isme kuch aisa h nhi ki ek hi baar pick krna h to loop k jrurt nhi h ki kisko first rkhe
    if (target >= candidates[ind])
    {
        ds.push_back(candidates[ind]);
        combination(candidates, target - candidates[ind], ind, ans, ds);
        ds.pop_back();
    }
    // donot pick itself
    combination(candidates, target, ind + 1, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    // hum kitna baar bhi choose kr skte h
    //  toh ek baar choose pick kro nd not pick kro
    vector<vector<int>> ans;
    vector<int> ds;
    combination(candidates, target, 0, ans, ds);
    return ans;
}

int main()
{

    return 0;
}