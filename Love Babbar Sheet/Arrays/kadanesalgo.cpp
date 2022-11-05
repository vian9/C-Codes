// Link : https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
// Isme O(n) mein krrhe by taking maxSum possible as minimum agar sav negative bhi hua to yhi return krdenge
// Harr iterations mein currentSum nikalenge jisse chceck krenge agar jada hua to maxSum update otherwise negative hua to zero

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long maxSubarraySum(int arr[], int n)
{
    ll maxSum = INT_MIN;
    ll currentSum = 0;
    for (ll i = 0; i < n; i++)
    {
        currentSum += arr[i];
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}

int main()
{

    return 0;
}