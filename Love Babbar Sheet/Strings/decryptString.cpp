// Link : https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
// Time Complexity : O(n)
// Approach-> Agar i+2 position par # hai toh (96+woh num) ka ascii char is added otherwise 96+s[i] num ka ascii char add krdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string freqAlphabets(string s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1' || s[i] == '2')
        {
            if (s[i + 2] == '#')
            {
                int num = s[i] - '0';
                num = num * 10;
                num += (s[i + 1] - '0');
                char val = (char)96 + num;
                ans += val;
                i += 2;
            }
            else
            {
                int num = s[i] - '0';
                char val = (char)96 + num;
                ans += val;
            }
        }
        else
        {
            int num = s[i] - '0';
            char val = (char)96 + num;
            ans += val;
        }
    }
    return ans;
}

int main()
{

    return 0;
}