// Link : https://leetcode.com/problems/longest-palindromic-subsequence/
// Time Complexity : O(n*m)
// Approach-> Longest common Subsequence nikalo dp se and to get Longest Pallindromic Subsequence just pass the string
// and the reverse of string....it will give the length of longest pallindrome

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int longestPalindromeSubseq(string s)
{
    // String initialise krdia of same length as s
    string s2(s.length(), ' ');
    // s2 mein s ko copy krdia
    s2 = s;
    // reverse krdia s2
    reverse(s2.begin(), s2.end());
    return longestCommonSubsequence(s, s2);
}

// Dp- Tabulation - Time : O(n*m) and Space : O(n+m)
int longestCommonSubsequence(string text1, string text2)
{
    // Base Case
    if (text1.length() == 0 || text2.length() == 0)
    {
        return 0;
    }
    int n = text1.length();
    int m = text2.length();
    // Length of vector will be equal to row no
    vector<int> prevRow(m + 1, 0);
    vector<int> currRow(m + 1, 0);
    // phla row ka savka value 0 k barabar
    for (int j = 0; j <= m; j++)
    {
        prevRow[j] = 0;
    }
    // Index shifted....0 par jb koi char nhi lia
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                // Jahan jahan i-1 tha mtlb prev row and i tha mtlb current row
                currRow[j] = 1 + prevRow[j - 1];
            }
            // agar match nhi hua toh ek peche jayega and ek nhi aur unme se max length
            else
                currRow[j] = max(prevRow[j], currRow[j - 1]);
        }
        // This line directly copies value from one vector to another if dimension of vector is same
        prevRow = currRow;
    }
    // Last mein longest value store ho jayega
    return prevRow[m];
}

int main()
{

    return 0;
}