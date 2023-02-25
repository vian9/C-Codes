// Link : https://leetcode.com/problems/add-to-array-form-of-integer/
// Time Complexity : O(n)
// Approach-> Directly add krne se int k limit k baad add multiply nhi ho payega
// so instead vector main add krte jao nd usme hi push krte jao nd finally reverse.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> addToArrayForm(vector<int> &num, int k)
{
    int len = num.size() - 1;
    vector<int> ans;
    int carry = 0;
    while (k > 0 && len >= 0)
    {
        int dig = k % 10;
        k = k / 10;
        int sum = num[len] + dig + carry;
        carry = 0;
        if (sum > 9)
        {
            carry = 1;
            sum = sum - 10;
        }
        len--;
        ans.push_back(sum);
    }
    while (k > 0)
    {
        int dig = k % 10;
        k = k / 10;
        dig += carry;
        carry = 0;
        if (dig > 9)
        {
            carry = 1;
            dig -= 10;
        }
        ans.push_back(dig);
    }
    while (len >= 0)
    {
        int dig = num[len];
        dig += carry;
        carry = 0;
        if (dig > 9)
        {
            carry = 1;
            dig -= 10;
        }
        ans.push_back(dig);
        len--;
    }
    if (carry > 0)
    {
        ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}