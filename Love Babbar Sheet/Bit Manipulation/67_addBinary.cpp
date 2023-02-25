// Link : https://leetcode.com/problems/add-binary/
// Time Complexity : O(n)
// Approach-> Merge sort k jaisa...just ek string khtm hua to dusra nd tesra jbtk over nhi hoga loop lgado
// Ab binary number ko add kroge to 0, 1, 2 nd 3 tk jayega tb usme carry kya rkhna h nd push kya krna h dekhlo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string addBinary(string a, string b)
{
    int carry = 0;
    int len1 = a.length() - 1;
    int len2 = b.length() - 1;
    string ans;
    while (len1 >= 0 && len2 >= 0)
    {
        int num1 = (a[len1] - '0');
        int num2 = (b[len2] - '0');
        len1--;
        len2--;
        int sum = num1 + num2;
        if (carry != 0)
        {
            sum += carry;
            carry = 0;
        }
        if (sum == 2)
        {
            carry = 1;
            ans.push_back('0');
        }
        else if (sum == 3)
        {
            carry = 1;
            ans.push_back('1');
        }
        else
        {
            char a = sum + '0';
            ans.push_back(a);
        }
    }
    while (len1 >= 0)
    {
        int num1 = (a[len1] - '0');
        len1--;
        int sum = num1;
        if (carry != 0)
        {
            sum += carry;
            carry = 0;
        }
        if (sum == 2)
        {
            carry = 1;
            ans.push_back('0');
        }
        else if (sum == 3)
        {
            carry = 1;
            ans.push_back('1');
        }
        else
        {
            char a = sum + '0';
            ans.push_back(a);
        }
    }
    while (len2 >= 0)
    {
        int num2 = (b[len2] - '0');
        len2--;
        int sum = num2;
        if (carry != 0)
        {
            sum += carry;
            carry = 0;
        }
        if (sum == 2)
        {
            carry = 1;
            ans.push_back('0');
        }
        else if (sum == 3)
        {
            carry = 1;
            ans.push_back('1');
        }
        else
        {
            char a = sum + '0';
            ans.push_back(a);
        }
    }
    if (carry != 0)
    {
        ans.push_back('1');
    }
    string finalAns;
    for (int i = ans.length() - 1; i >= 0; i--)
    {
        finalAns.push_back(ans[i]);
    }
    return finalAns;
}

int main()
{

    return 0;
}