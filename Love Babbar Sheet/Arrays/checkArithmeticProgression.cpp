// Link : https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// Time Complexity : O(n)
// Approach-> Bas sort krdo aur check kro ki diff same h na agar same nhi rha toh return false.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool canMakeArithmeticProgression(vector<int> &arr)
{
    // No need of base case ki size < 2 as given in ques size  2.
    sort(arr.begin(), arr.begin() + arr.size());
    int diff = arr[1] - arr[0];
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] - arr[i] != diff)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}