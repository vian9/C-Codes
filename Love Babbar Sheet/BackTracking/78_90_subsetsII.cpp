// Link : https://leetcode.com/problems/subsets-ii/
// Link : https://leetcode.com/problems/subsets/submissions/
// Time Complexity : O(2^n)
// Approach-> Phle kisi ek se start kro nd instead of recursive call wo usse ind se N tk loop pr call krdo nd
// same rha to skip kro

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// we want all the subset without duplicates....not just sum....toh uske liye ds m push krte jayenge
void subsetWithDupes(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int N, int ind)
{
    ans.push_back(ds);

    // ek se start kiya and uske saare different possibility pr jayega
    for (int i = ind; i < N; i++)
    {
        // This line is to skip the duplicate subsets
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        // ab yeh i se call kro agla i+1 ko pick krne k liye
        subsetWithDupes(nums, ans, ds, N, i + 1);
        // pop kro kuuki next iterate m kahin aur jayega
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int N = nums.size();
    sort(nums.begin(), nums.end());
    subsetWithDupes(nums, ans, ds, N, 0);
    return ans;
}
int main()
{

    return 0;
}