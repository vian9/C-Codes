// Link : https://leetcode.com/problems/multiply-strings/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string multiply(string num1, string num2)
{
    // last digit se start kro multiply krke string m push_front kro
    vector<int> ans;
    int n = num1.length();
    int m = num2.length();
    int carry = 0;
    int mul = 0;
    int i = n - 1;
    int j = m - 1;
    int digit = 1;
    while (i >= 0 && j >= 0)
    {
        int dig1 = num1[i] - '0';
        int dig2 = num2[j] - '0';
        mul = dig1 * dig2 * digit;
        if (carry == 1)
            mul += 1;
        carry = 0;
        digit = digit * 10;
        if (mul > 9)
        {
            carry = 1;
            mul = mul - 10;
        }
        ans.push_back(mul);
        i--;
        j--;
    }
    while (i >= 0)
    {
        int dig1 = num1[i] - '0';
        dig1 += carry;
        carry = 0;
        if (dig1 > 9)
        {
            carry = 1;
            dig1 -= 10;
        }
        ans.push_back(dig1);
        i--;
    }
    while (j >= 0)
    {
        int dig2 = num2[j] - '0';
        dig2 += carry;
        carry = 0;
        if (dig2 > 9)
        {
            carry = 1;
            dig2 -= 10;
        }
        ans.push_back(dig2);
        j--;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }

    return "";
}

int main()
{

    return 0;
}