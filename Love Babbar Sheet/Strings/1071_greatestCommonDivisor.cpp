// Link : https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Time Complexity : O(1)
// Approach-> Dekho agar string repeat horha h toh dono ko add krne pr bhi repeat hoga and add krke dono side se check krlo
// aur length to return will be gcd of their length....max num that can divide both

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string gcdOfStrings(string str1, string str2)
{
    if (str1 + str2 == str2 + str1)
    {
        return (str1.substr(0, gcd(str1.length(), str2.length())))
    }
    return "";
}

int main()
{

    return 0;
}