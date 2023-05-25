// Link : https://leetcode.com/problems/longest-consecutive-sequence/
// Time Complexity : O(n)
// Approach-> Map m daldo and jha se num-1 exist nhi krrha h wha se map m check kro nd len nikalo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int longestConsecutive(vector<int> &nums)
{
    // Brute force is sort krdo
    // Hash use krdo
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] = 1;
    }

    int count = 0;
    for (auto num : nums)
    {
        // agar num-1 exist nhi krrha h tbhi wha se check kro
        if (mp.count(num - 1) == 0)
        {
            int maxi = 0;
            while (mp.count(num + 1) > 0)
            {
                maxi++;
                num++;
            }
            // min 1 to save hoga hi agar 1 size k array h
            maxi += 1;
            count = max(count, maxi);
        }
    }

    return count;
}

int main()
{

    return 0;
}