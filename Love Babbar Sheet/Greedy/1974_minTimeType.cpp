// Link : https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
// Time Complexity : O(n)
// Approach-> Dekho ya phir start se kro ya end se kro dono m se jo min hoga wo type count h and ab point wha aagya

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minTimeToType(string word)
{
    // hum khi se start krenge
    int len = word.length(), point = 'a';
    // start to 0 se hi krenge na
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        int curr = word[i];
        // min of either ki curr se point tk ya phir reverse se toh 26 se minus krdo
        count += min(abs(curr - point), 26 - abs(point - curr));
        point = word[i];
        count++;
    }
    return count;
}

int main()
{

    return 0;
}