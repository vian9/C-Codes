// Link : https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
// Time Complexity : O(n)
// Approach-> Took 2 Pointer Approach....O(1) Space complexity
// Just took 2 variables to store index where the characters in strings are not equal.
// Swap the character in any of the string at the given index and check if string are equal.
// M-2 - [ ] map.count value nhi deta hai....wo btata h ki wo key present h bas.....bool funct hai only returns 0 or 1 na ki value

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool areAlmostEqual(string s1, string s2)
{
    // M-1
    int l = 0;
    int r = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if ((s1[i] != s2[i]) && l == 0)
        {
            l = i;
        }
        else if ((s1[i] != s2[i]) && l != 0)
        {
            r = i;
            break;
        }
    }
    swap(s1[l], s1[r]);

    if (s1 == s2)
    {
        return true;
    }

    return false;

    // M-2 : Was trying with taking a total count of distinct elements.....
    // - [ ] In above code….agar freq minus krne k baad 0 aagya to usse delete kr denge….
    // otherwise freq.count is not checking value it’s check if that key is present even if value is 0…..
    // toh erase k baad key nhi h to count 0 hoga and else mein chal jayega
    if (s1.length() != s2.length())
    {
        return false;
    }
    int count = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            count++;
        }
    }
    unordered_map<char, int> freq;
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i]] += 1;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        if (freq.count(s2[i]) > 0)
        {
            freq[s2[i]] -= 1;
            if (freq[s2[i]] == 0)
            {
                freq.erase(s2[i]);
                if (freq.count(s2[i]) > 0)
                {
                    cout << "jo" << freq[s2[i]] << endl;
                }
            }
        }
        else
        {
            return false;
        }
    }

    if (count > 2)
        return false;
    else
        return true;
}

int main()
{

    return 0;
}