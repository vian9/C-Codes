// Link : https://leetcode.com/problems/find-the-difference/
// Time Complexity : O(n)
// Approach-> Add the ASCII Value of all char in s and t. The extra char is diff of sum ka ascii value.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

char findTheDifference(string s, string t)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
        sum += (int)s[i];
    int sum2 = 0;
    for (int i = 0; i < t.length(); i++)
        sum2 += (int)t[i];

    return sum2 - sum;
}

int main()
{

    return 0;
}