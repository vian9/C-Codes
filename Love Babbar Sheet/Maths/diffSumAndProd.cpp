// Link : https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
// Time Complexity : O(n)....n is no of igits
// Approach-> Last digit ko lia by taking remainder on 10 and uska prod and sum mein krdiya and finally n ko by 10 divide.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int subtractProductAndSum(int n)
{
    int sum = 0;
    int prod = 1;
    while (n > 0)
    {
        int last = n % 10;
        prod = prod * last;
        sum += last;
        n = n / 10;
    }
    return prod - sum;
}

int main()
{

    return 0;
}