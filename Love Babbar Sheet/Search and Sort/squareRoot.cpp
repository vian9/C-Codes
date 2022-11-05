// Link : https://leetcode.com/problems/sqrtx/
// Time Complexity : O(logn)
// Approach-> Binary Search approach of divide and conquer....square root of a number x will lie btw 0 and x
// Ab we only has to return integer issliye check for if mid square <= x and mid+1 square > x....toh mid is ans
// otherwise mid square se bada h toh start ko mid+1 else mid square se chota h to end mid-1

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Solution 1
int sqr(int x, int start, int end)
{
    long mid = (start + end) / 2;
    if (x == 1 || x == 0)
    {
        return x;
    }
    if (start <= end)
    {
        // yeh mid * mid <= x mein <= is imp kuuki agar mid k square se x bada h but mid+1 sqaure se chota toh bhi ans will be mid
        if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
        {
            return mid;
        }
        else if (mid * mid > x)
        {
            return sqr(x, start, mid - 1);
        }
        else
        {
            return sqr(x, mid + 1, end);
        }
    }

    return mid;
}

// Solution 2
int mySqrt(int x)
{
    int start = 0;
    int end = x;
    int ans = 0;
    while (start <= end)
    {
        long mid = (start + end) / 2;
        if (mid * mid == x)
        {
            ans = mid;
            return mid;
        }
        else if (mid * mid > x)
        {
            end = mid - 1;
        }
        else
        {
            // Agar mid sqaure se bada h x toh update ans = mid taki agar mid+1 k sqaure se x
            //  chota hua toh ans will be this mid then
            start = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

// Solution 3
int mySqrt(int x)
{
    int start = 0;
    int end = x;
    while (start <= end)
    {
        long mid = (start + end) / 2;

        // agar mid square se bada h x but mid+1 square se chota h x to ans is mid
        if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
        {
            return mid;
        }

        if (mid * mid > x)
        {
            end = mid - 1;
        }
        else if (mid * mid < x)
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{

    return 0;
}