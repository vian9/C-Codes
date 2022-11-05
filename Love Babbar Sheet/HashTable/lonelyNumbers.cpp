// Link : https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
// Time Complexity : O(n)
// Approach-> Map mein freq daal dia....ab check for map agar uska freq 1 ho and x+1 and x-1 nhi aarha ho to woh vector mein daldo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> findLonely(vector<int> &nums)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;
    }
    vector<int> ans;
    for (auto &i : freq)
    {
        if (i.second == 1)
        {
            // Count gives 0 or 1....toh agar x+1 key exist nhi krrha toh 0 return krta h
            if (freq.count(i.first + 1) < 1 && freq.count(i.first - 1) < 1)
            {
                ans.push_back(i.first);
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}