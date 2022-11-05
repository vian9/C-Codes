// Link : https://leetcode.com/problems/rotate-array/
// Time Complexity : O(n)
// Approach-> Phle peeche mein push back kia and phir aage mein erase jo repeated tha

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void rotate(vector<int> &nums, int k)
{
    if (k == 0 || nums.size() == 1)
    {
        return;
    }
    // Hume remainder chahiye whi actual number of rotations dega for k > nums.size() condition
    k = (k % nums.size());

    int n = nums.size();
    for (int i = 0; i < n - k; i++)
    {
        nums.push_back(nums[i]);
    }
    nums.erase(nums.begin(), nums.begin() + n - k);
}

int main()
{

    return 0;
}