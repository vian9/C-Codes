// Link : https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
// Time Complexity : O(n)
// Approach-> Last wale k value se dekho and usse +1 rkhna h to keep increasing so at present sbka sochkr krte jao

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minOperations(vector<int> &nums)
{
    // we have to strictly make increasing
    int last = nums[0];
    int minop = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] <= last)
        {
            minop += (last - nums[i] + 1);
            last += 1;
        }
        else
        {
            last = nums[i];
        }
    }
    return minop;
}

int main()
{

    return 0;
}