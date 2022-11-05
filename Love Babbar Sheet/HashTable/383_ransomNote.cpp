// Link : https://leetcode.com/problems/ransom-note/
// Time Complexity : O(n)
// Approach-> Phle hash map mein daal dia aur phir check krlia ki hai ya nhi aur agar freq == 0 hua toh erase that from map

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> freq;
    for (int i = 0; i < magazine.length(); i++)
    {
        freq[magazine[i]] += 1;
    }

    for (int i = 0; i < ransomNote.length(); i++)
    {
        if (freq.count(ransomNote[i]) > 0)
        {
            freq[ransomNote[i]]--;
            if (freq[ransomNote[i]] == 0)
                freq.erase(ransomNote[i]);
        }
        else
        {
            return false;
        }
    }
    return false;
}

int main()
{

    return 0;
}