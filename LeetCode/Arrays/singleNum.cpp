// Link : https://leetcode.com/problems/single-number/
// Time Complexity : O(n) and Space Complexity is O(1)
// Approach-> Just take XOR of all the numbers and it will give
// the final number which appeared once.....logic is XOR of any no.
// with itself is 0 that's why only 1 number is left.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int singleNumber(vector<int> &nums)
{
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        ans = (ans ^ nums[i]);
    }
    return ans;
}

int main()
{

    return 0;
}