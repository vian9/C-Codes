// VVI
// Link : https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// Time Complexity : O(n)
// Approach-> Approach is we are trying to find total number of times a number comes in even or odd length and
// phir uske value se multiply krke add is the ans
// For any num at ith iterations.....left side se woh i baar and including one itself [arr[i]] will be i+1
// For right side it will be n-i
// For even length just total/2 is frequency but for odd length it is (total+1)/2

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int sumOddLengthSubarrays(vector<int> &arr)
{
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum += (((i + 1) * (n - i) + 1) / 2) * arr[i];
    }
    return sum;
}

int main()
{

    return 0;
}