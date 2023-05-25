// Link : https://leetcode.com/problems/powx-n/
// Time Complexity : O(n/2)
// Approach-> n/2 lelo and agar 2 ka multiple h to directly whi multiply otherwise cases

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
    {
        return x;
    }
    if (n == -1)
    {
        return 1 / x;
    }
    double temp = myPow(x, n / 2);
    // if multiple of 2 then temp square
    if (n % 2 == 0)
    {
        return temp * temp;
    }
    else if (n > 0)
    {
        // otherwise x ka power +1 k liye
        return temp * temp * x;
    }
    else
    {
        // otheriwse denominator m power lne k liye
        return ((temp) * (temp)*1 / x);
    }
}

int main()
{

    return 0;
}