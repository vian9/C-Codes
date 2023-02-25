// Link : https://leetcode.com/problems/combination-sum-ii/
// Time Complexity : O(2^k)
// Approach-> Isme pick ek ko nd do avoid duplicate sort krdo nd next same rha to ignore it nd then call

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Isme bs ek baar input krna h nd duplicates nhi hona chahiye
void combination(vector<int> &candidates, int target, int ind, vector<vector<int>> &ans, vector<int> &ds)
{
    int n = candidates.size();

    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    // pick kro nd uske next wla same h toh don't pick it nd uske baad ab call krdo savkr
    for (int i = ind; i < n; i++)
    {
        if (i > ind && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        ds.push_back(candidates[i]);
        combination(candidates, target - candidates[i], i + 1, ans, ds);
        ds.pop_back();
    }
}

// duplicates nhi hone k liye hum phle sort kr denge and agar same element aayega to ignore
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    // hum kitna baar bhi choose kr skte h
    //  toh ek baar choose pick kro nd not pick kro
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    combination(candidates, target, 0, ans, ds);
    return ans;
}

int main()
{

    return 0;
}