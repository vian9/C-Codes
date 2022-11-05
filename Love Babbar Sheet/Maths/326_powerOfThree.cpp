// Link : https://leetcode.com/problems/power-of-three/
// Time Complexity : O(logn)
// Approach-> Agar 1 hogya toh return as it is 3^0 uske alawa agar kisi bhi time divisible nhi h to return false
// Call for recursion for n/3;

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPowerOfThree(int n)
{
    if (n < 1)
        return false;
    if (n == 1)
        return true;
    if (n % 3 != 0)
        return false;
    n = n / 3;
    return isPowerOfThree(n);
}

int main()
{

    return 0;
}