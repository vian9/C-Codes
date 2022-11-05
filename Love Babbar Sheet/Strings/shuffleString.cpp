// Link : https://leetcode.com/problems/shuffle-string/
// Time Complexity : O(n)
// Approach-> String lelia of size s.length and ab uske indices mein wo s se dalte gye

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string restoreString(string s, vector<int> &indices)
{
    char x = ' ';
    string str(s.length(), x);
    for (int i = 0; i < s.length(); i++)
    {
        str[indices[i]] = s[i];
    }
    return str;
}

int main()
{

    return 0;
}