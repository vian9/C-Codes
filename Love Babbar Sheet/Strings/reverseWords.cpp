// Link : https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Time Complexity : O(nlogn)...not sure
// Approach-> 2 Pointer Approach.....start ko word k start kr rkha and end ko word k end k baad space pr and uska
// substring lia and usse finally reverse krke string mein add krdia

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string reverseString(string &s)
{
    int n = s.length();
    for (int i = 0; i < s.length() / 2; i++)
    {
        char first = s[i];
        char last = s[n - i - 1];
        s[i] = last;
        s[n - i - 1] = first;
    }
    return s;
}

string reverseWords(string s)
{
    string rev = "";
    int start = 0;
    int end = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ' || (i == s.length() - 1))
        {
            end = i;
            int len = end - start;
            // Agar last of string h toh end kisi space pr nhi but last char pr hoga issliye +1 taki pura len mil ske
            if (i == s.length() - 1)
                len = end - start + 1;
            string sub = s.substr(start, len);
            rev += reverseString(sub);
            // Agar end of string nhi h tbhi space add kro otherwise end mein jrurt nhi
            if (i != s.length() - 1)
            {
                rev += " ";
            }
            start = i + 1;
        }
    }
    return rev;
}
int main()
{
    return 0;
}