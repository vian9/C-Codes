// Link : https://leetcode.com/problems/to-lower-case/
// Time Complexity : O(n)
// Approach-> Agar capital letter h to usko lowercase k liye just 32 add krdo.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string toLowerCase(string s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        int num = (int)s[i];
        if (num >= 65 && num <= 90)
        {
            num += 32;
        }
        ans += (char)num;
    }
    return ans;
}

int main()
{

    return 0;
}