// Link : https://leetcode.com/problems/ugly-number/description/
// Time Complexity : O(n/2)
// Approach-> 2,3 and 5 se jbtk divide krte jao jbtk ho ske

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Prime factors should be 2, 3 or 5
bool isUgly(int n)
{
    // number should be positive integer
    if (n <= 0)
    {
        return false;
    }
    // 2, 3 and 5 se divide krdo jbtk ho ske
    while (n % 2 == 0)
        n = n / 2;
    while (n % 3 == 0)
        n = n / 3;
    while (n % 5 == 0)
        n = n / 5;
    // agar prime factor bas 2,3 and 5 hoga to bss 1 bachega
    if (n == 1)
    {
        return true;
    }
    return false;
}

int main()
{

    return 0;
}