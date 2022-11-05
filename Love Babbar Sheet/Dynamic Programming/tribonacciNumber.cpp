// Link : https://leetcode.com/problems/n-th-tribonacci-number/
// Time Complexity : O(n) Time and O(1) Space
// Approach-> DP with 3 variables.....ab usko store krte gye and return....similar to fibonacci

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int tribonacci(int n)
{
    int prev3 = 0;
    int prev2 = 1;
    int prev = 1;
    if (n < 1)
        return prev3;
    for (int i = 3; i < n + 1; i++)
    {
        int curr = prev + prev2 + prev3;
        prev3 = prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{

    return 0;
}