// Link : https://leetcode.com/problems/valid-palindrome-ii/
// Time Complexity : O(n)
// Approach-> Deleteing a char will result in a pallindrome...to uske liye default var se ek hi func m krne k liye
// start aur end de denge and ek flag de denge jisse ki ab edit nhi ho skta and recursively return krdega

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool validPalindrome(string s, int left = 0, int right = -1, bool flag = false)
{
    int len = s.length();
    if (right == -1)
        right = s.length() - 1;
    if (len <= 1 || (right - left) == 0)
    {
        cout << "a" << endl;
        return true;
    }
    // flag for ki ek baar change krdia ab mt krna
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else if (!flag)
        {
            // agar kahi skip krna h to ek shift krke bhej do for pallindrome either from left or from right
            return (validPalindrome(s, left + 1, right, true) || validPalindrome(s, left, right - 1, true));
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}