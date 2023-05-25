// Link : https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
// Time Complexity : O(n)
// Approach-> Min and Max lelo and ab ek min and ek max k combo bnalo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minimumSum(int num)
{
    int min1 = -1;
    int min2 = -1;
    int max1 = -1;
    int max2 = -1;
    while (num > 0)
    {
        int dig = num % 10;
        num /= 10;
        if (min1 == -1)
            min1 = dig;
        else if (min2 == -1)
            min2 = dig;
        // either replace
        else if (min1 != -1 && dig < min1)
        {
            int dit = min1;
            if (min1 < min2)
            {
                dit = min2;
                min2 = min1;
            }
            // Max m daldo agar khali h
            if (max1 == -1)
                max1 = dit;
            else if (max2 == -1)
                max2 = dit;
            min1 = dig;
        }
        else if (min2 != -1 && dig < min2)
        {
            int dit = min2;
            if (min2 < min1)
            {
                dit = min1;
                min1 = min2;
            }
            if (max1 == -1)
                max1 = dit;
            else if (max2 == -1)
                max2 = dit;
            min2 = dig;
        }
        // or max m chal jaye
        else
        {
            if (max1 == -1)
                max1 = dig;
            else if (max2 == -1)
                max2 = dig;
        }
    }
    int num1 = min1 * 10 + max1;
    int num2 = min2 * 10 + max2;
    return num1 + num2;
}

int main()
{

    return 0;
}