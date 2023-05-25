// Link : https://leetcode.com/problems/next-permutation/
// Time Complexity : O(n)
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void nextPermutation(vector<int> &nums)
{
    // lexographical order is next sequence possible with the numbers...123 k baad 132

    int index = -1;
    int n = nums.size();
    // Agar i wale digit se bda right mein exist krrha toh wha se index lelo
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }
    // Ab right wla exist krrha bda usse index ko swap krdo toh mjhe usse bda lexigraphical mil jayega
    for (int i = n - 1; i > index && index != -1; i--)
    {
        if (nums[i] > nums[index])
        {
            swap(nums[i], nums[index]);
            break;
        }
    }
    // ab next chahiye to index k aage se reverse krdo
    reverse(nums.begin() + index + 1, nums.end());
}

int main()
{

    return 0;
}