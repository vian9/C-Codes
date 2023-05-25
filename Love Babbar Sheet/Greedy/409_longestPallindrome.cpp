// Link : https://leetcode.com/problems/longest-palindrome/
// Time Complexity : O(n)
// Approach-> Map mein store krte gye char and usse pallindrome bn skta wo dekhna h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int longestPalindrome(string s)
{
    int len = s.length();
    unordered_map<char, int> mp;
    for (int i = 0; i < len; i++)
    {
        mp[s[i]]++;
    }
    int maxi = 0;
    int count = 0;
    bool flag = false;
    for (auto i : mp)
    {
        // if count of that char is divisible by 2 to pallindrome m dal do
        if (i.second % 2 == 0)
        {
            count += i.second;
        }
        else
        {
            // otherwise ek baar 1 lelia h to ab jb bhi odd lo to even ke count mein lenge
            if (flag)
            {
                // ab ek odd lelia toh even m lenge for pallindrome
                count += (i.second - 1);
            }
            else
            {
                // ek bhi odd ho toh bhi lelia hmne ab even no of odds lena h
                count += i.second;
                flag = true;
            }
        }
    }
    return count;
}

int main()
{

    return 0;
}