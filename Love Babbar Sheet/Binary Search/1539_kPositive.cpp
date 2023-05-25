// Link : https://leetcode.com/problems/kth-missing-positive-number/
// Time Complexity : O(logn)
// Approach-> koi bhi number se phle (arr - i + 1) number reh jayega....to yhi logic se binary search se val nikalo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size();
    while (low < high)
    {
        int mid = (high - low) / 2 + low;
        if (arr[mid] - mid > k)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low + k;
}

int main()
{

    return 0;
}