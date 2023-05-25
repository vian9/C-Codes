// Link : https://leetcode.com/problems/two-sum/
// Time Complexity : O(n) and Space : O(n)
// Approach-> num[i] pr target-num[i] check kro ki exist krta h....and nhi to map m update kro

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Ek num lelo and map m dalte jao and check kro phle target - num[i] aaya h
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.count(target - nums[i]) > 0 && (mp[target - nums[i]] != i))
        {
            ans.push_back(min(i, mp[target - nums[i]]));
            ans.push_back(max(mp[target - nums[i]], i));
            break;
        }
        // repeated nums update na ho taki history check kr ske
        mp[nums[i]] = i;
    }
    return ans;
}

int main()
{

    return 0;
}