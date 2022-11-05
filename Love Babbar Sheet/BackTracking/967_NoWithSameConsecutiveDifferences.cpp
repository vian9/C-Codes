// Link : https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// Time Complexity : O(n * len)
// Approach-> First digit lia aur bhejdia.....phir saara combinations try krrha hu

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void helper(int len, int k, num, int digit, vector<int> &ans)
{
    if (len == 0)
    {
        ans.push_back(num);
        return ans;
    }
    for (int i = 0; i < 10; i++)
    {
        if (abs(i - digit) == k)
        {
            helper(len - 1, k, num * 10 + i, i, ans);
        }
    }
}

vector<int> numsSameConsecDiff(int n, int k)
{
    if (k == 0)
    {
        vector<int> ans;
        int numEnd = 9;
        for (int i = 1; i <= 9; i++)
        {
            int num = i;
            int digits = n - 1;
            while (digits)
            {
                num = (num * 10 + i);
                digits--;
            }
            ans.push_back(num);
        }
        return ans;
    }
    vector<int> ans;
    for (int i = 1; i <= 9; i++)
    {
        helperl(n - 1, k, i, i, ans);
    }

    return ans;
}

int main()
{

    return 0;
}