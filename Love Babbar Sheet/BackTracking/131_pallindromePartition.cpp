// Link : https://leetcode.com/problems/palindrome-partitioning/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// To check given substring is a pallindrome
bool isPallindrome(int start, int end, string s)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

// Whi kaam krrhe h...pick kro and check ki pallindrome h and then usko unpick krdo
void myCombo(vector<vector<string>> &ans, vector<string> &ds, string &s, int index, int n)
{
    if (index >= n)
    {
        ans.push_back(ds);
        return;
    }

    // Index se i tk ko ek substr m pick kro...ye loop is to pick the start partition line
    for (int i = index; i < n; i++)
    {
        if (isPallindrome(index, i, s))
        {
            ds.push_back(s.substr(index, i - index + 1));
            myCombo(ans, ds, s, i + 1, n);
            // pick jha tk kiye usko pop krdo
            ds.pop_back();
        }
    }
}

// Substring so continous
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> ds;
    myCombo(ans, ds, s, 0, s.length());
    return ans;
}

int main()
{

    return 0;
}