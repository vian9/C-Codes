// Link : https://leetcode.com/problems/valid-palindrome/
// Time Complexity : O(n)
// Approach-> Phle ek vector lia and usme alphabets and numbers push krdia....baaki jo bhi bacha usse
// ignore krdia.....ab stack mein vector se push kia and phir stack k top(last of string) check kia with
// first of vector and same h to pop krdia

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPalindrome(string s)
{
    vector<char> str;
    for (int i = 0; i < s.length(); i++)
    {
        int a = (int)s[i];
        if (a >= 65 && a <= 90)
        {
            char ch = s[i] + 32;
            str.push_back(ch);
        }
        else if (a >= 97 && a <= 122)
        {
            str.push_back(s[i]);
        }
        else if (a >= 48 && a <= 57)
        {
            str.push_back(s[i]);
        }
    }
    stack<char> stk;
    for (int i = 0; i < str.size(); i++)
    {
        stk.push(str[i]);
    }
    bool check = true;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == stk.top())
        {
            stk.pop();
        }
        else
        {
            check = false;
            break;
        }
    }
    return check;
}

int main()
{

    return 0;
}