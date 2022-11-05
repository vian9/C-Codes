// Link : https://leetcode.com/problems/find-pivot-index/
// Time Complexity : O(n)....good logic
// Approach-> Prefix Sum......Dekho simply mjhe phle pura right k sum chahiye to uske liye harr step pr
// hum rightSum mein nums subtracct kia and if left se equal to return i and phir left sum mein nums add krdo agar equal nhi to

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int pivotIndex(vector<int> &nums)
{
    int rightSum = 0;
    int sum = 0;
    int lsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    rightSum = sum;
    for (int i = 0; i < nums.size(); i++)
    {
        rightSum -= nums[i];
        if (rightSum == lsum)
        {
            return i;
        }
        lsum += nums[i];
    }
    return -1;
}

int main()
{

    return 0;
}