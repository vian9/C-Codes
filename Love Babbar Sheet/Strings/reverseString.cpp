// Link : https://leetcode.com/problems/reverse-string/
// Time Complexity : O() nd O(1) extra space only
// Approach-> Left wale ko first mein and right wale ko last mein store krdia and fir swap krdia....did for half loop

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void reverseString(vector<char> &s)
{
    int n = s.size();
    for (int i = 0; i < s.size() / 2; i++)
    {
        char first = s[i];
        char last = s[n - i - 1];
        s[i] = last;
        s[n - i - 1] = first;
    }
}

int main()
{

    return 0;
}