// Link : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Time Complexity : O(1)
// Approach-> Logic is agar dono even hua to diff by 2 is the total count othewise ek bhi even and odd or
// dono odd hua toh wo odd wala inclusive hai toh diff by 2 + 1 bi aayega.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int countOdds(int low, int high)
{
    if (low % 2 == 0 && high % 2 == 0)
    {
        // can't write (high - (high+low)/2) bcoz here ek diff 1 hai toh by 2 par 0.5 nhi aayega 1 hi rhega.
        return (high - low) / 2;
    }
    else
    {
        return ((high - low) / 2) + 1;
    }
}

int main()
{

    return 0;
}