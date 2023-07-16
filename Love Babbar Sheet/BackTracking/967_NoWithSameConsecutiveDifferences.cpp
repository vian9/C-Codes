// Link : https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// Time Complexity : O(n * len)
// Approach-> First digit lia aur bhejdia.....phir saara combinations try krrha hu

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void helper(vector<int> &ans, vector<int> ds, int len, int k)
{
    if (len == 0)
    {
        // phla dig -1 h usse htakr saara se num lo ans m dalo
        int num = 0;
        for (int i = 1; i < ds.size(); i++)
        {
            num = num * 10 + ds[i];
        }
        ans.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        // if k se ya 1st digit h
        if (abs(i - ds.back()) == k || ds.back() == -1)
        {
            // agar 1st dig h to not 0
            if (ds.back() == -1 && i == 0)
                continue;
            // pick
            ds.push_back(i);
            helper(ans, ds, len - 1, k);
            // not pick se ab next iterate pr pick
            ds.pop_back();
        }
    }
}

// Now just tell ki n nd k kya h all ans will be given by pick not pick
vector<int> numsSameConsecDiff(int n, int k)
{
    if (k == 0)
    {
        vector<int> ans;
        for (int i = 1; i <= 9; i++)
        {
            int digit = n;
            int num = 0;
            while (digit)
            {
                num = num * 10 + i;
                digit--;
            }
            ans.push_back(num);
        }
        return ans;
    }
    vector<int> ans;
    vector<int> ds;
    ds.push_back(-1);
    helper(ans, ds, n, k);
    return ans;
}

void helper(int len, int k, int num, int digit, vector<int> &ans)
{
    // Base case
    if (len == 0)
    {
        ans.push_back(num);
        return ans;
    }
    // Pick not pick krrhe for all possible next digits
    for (int i = 0; i < 10; i++)
    {
        // agar diff k m h to call krdo pick krke
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
        // agar k == 0  hai to jo first digit hoga whi repeat hoga number m
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
    // first digit 0 ke alawa choose krke bhejdo
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