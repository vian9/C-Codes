// Link : https://leetcode.com/problems/contains-duplicate/
// Time Complexity : O(n)
// Approach-> Map mein true daaldo agar number aaya and check agar num phle se true hai to return true krdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, bool> check;
    for (int i = 0; i < nums.size(); i++)
    {
        if (check[nums[i]])
            return true;
        check[nums[i]] = true;
    }
    return false;
}

int main()
{

    return 0;
}