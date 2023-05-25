// Link : https://leetcode.com/problems/di-string-match/
// Time Complexity : O(n)
// Approach-> Dekho 2 pointer lelo and I and D jo h uske hisab se usme values dalo left ya right se

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> diStringMatch(string s)
{
    int len = s.length();
    vector<int> ans(len + 1, 0);
    // 2 var jo values move krayega
    int left = 0;
    int right = len;
    for (int i = 0; i < len; i++)
    {
        // Agar I hai toh left se value dalo chota wla jo ab i+1 aayega agar left se bhi to isse bada hoga wrna right se
        if (s[i] == 'I')
        {
            ans[i] = left;
            left++;
            // Agar last element h to agla wla daldo jo bhi bachrha h as array k len string k len se 1 jada h
            if (i == len - 1)
            {
                ans[i + 1] = left;
            }
        }
        else
        {
            ans[i] = right;
            right--;
            if (i == len - 1)
            {
                ans[i + 1] = right;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}