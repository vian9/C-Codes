// Link : https://leetcode.com/problems/rotate-string/
// Link : https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1
// Time Complexity : O(n)
// Approach-> Original string mein match krlia jahan phle char milrha and usko substring nikal kr aage add krke transform krdia
// Ab check krlia wo string nd goal same h to true otherwise aage loop jayega and kuch nhi mila to false

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// LeetCode and GeeksForGeeks
bool rotateString(string s, string goal)
{
    int start = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (goal[0] == s[i])
        {
            start = i;
            string sub = s.substr(start);
            sub = sub + s.substr(0, i);
            if (sub == goal)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}