// Link : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Time Complexity : O(n)
// Approach-> Sliding window k concept h....shift kro and peeche se 1 subtract krte jao

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxVowels(string s, int k)
{
    int len = s.length();
    unordered_map<char, int> mp;
    // map m sb daaldia saare vowels
    mp['a'] = 1;
    mp['e'] = 1;
    mp['i'] = 1;
    mp['o'] = 1;
    mp['u'] = 1;
    int maxi = 0;
    int count = 0;
    // Ab first k lelo
    for (int i = 0; i < k; i++)
    {
        count += mp.count(s[i]);
    }
    maxi = count;
    // Ab k se start kro and ek shift krte jao byy subtracting
    for (int i = k; i < len; i++)
    {
        count += (mp.count(s[i]) - mp.count(s[i - k]));
        maxi = max(maxi, count);
    }
    return maxi;
}

int main()
{

    return 0;
}