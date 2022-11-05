// VVI Approach
// Link : https://leetcode.com/problems/squares-of-a-sorted-array/
// Time Complexity : O(n)
// Approach-> Two Pointer Approach : Left and Right pointers lelia and ab left mein negative and right mein positive
// Jo jada bada hoga usko hum vector mein peeche se dalte jayenge

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> square(nums.size(), 0);
    int left = 0;
    int right = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (abs(nums[left]) > nums[right])
        {
            square[i] = nums[left] * nums[left];
            left++;
        }
        else
        {
            square[i] = nums[right] * nums[right];
            right--;
        }
    }

    return square;
}

int main()
{

    return 0;
}