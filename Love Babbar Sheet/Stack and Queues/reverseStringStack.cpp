// Link : https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1
// Time Complexity : O(n) and O(n) extra space
// Approach-> Just pushed char into stack and like LIFO jo top pr aayega wo string k last element h...now just copy the top element into string array and return.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

char *reverse(char *S, int len)
{
    char *rev = new char[len];
    stack<char> reve;
    for (int i = 0; i < len; i++)
    {
        reve.push(S[i]);
    }
    for (int i = 0; i < len; i++)
    {
        rev[i] = reve.top();
        reve.pop();
    }
    return rev;
}

int main()
{

    return 0;
}