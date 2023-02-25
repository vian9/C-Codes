// Link : https://leetcode.com/problems/reverse-words-in-a-string/description/
// Time Complexity : O(n)
// Approach-> Using the concept of 2 pointers.....string pr iterate kia....ab using while loop space ko skip kro
// and now make a substr i and j se and push in a vector....and phir spaces ko skip
// Ab ek string m lo aur concatenate krdo vector ko ulta

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string reverseWords(string s)
{
    vector<string> ans;
    for (int i = 0; i < s.length(); i++)
    {
        int j = i;
        while (s[j] == ' ' && j < s.length())
        {
            j++;
        }
        i = j;
        while (s[j] != ' ' && j < s.length())
        {
            j++;
        }
        string sbt = s.substr(i, j - i);
        ans.push_back(sbt);
        while (s[j] == ' ' && j < s.length())
        {
            j++;
        }
        i = j - 1;
    }
    string final;
    for (int i = ans.size() - 1; i > 0; i--)
    {
        final += ans[i];
        final += ' ';
    }
    final += ans[0];
    return final;
}
int main()
{

    return 0;
}