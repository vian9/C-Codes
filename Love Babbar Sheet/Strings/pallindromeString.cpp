// Link : https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
// Time Complexity : O(n)
// Approach-> Phle stack mein push krdia and phir check krlia ki stack k top and string k start same h to pop
// and agar pura match hua to pallindrome

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int isPalindrome(string S)
{
    stack<char> stk;
    for (int i = 0; i < S.length(); i++)
    {
        stk.push(S[i]);
    }
    int check = 1;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == stk.top())
        {
            stk.pop();
        }
        else
        {
            check = 0;
            break;
        }
    }
    return check;
}

int main()
{

    return 0;
}