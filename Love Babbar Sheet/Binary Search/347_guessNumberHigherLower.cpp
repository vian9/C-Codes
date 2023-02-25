// Link : https://leetcode.com/problems/guess-number-higher-or-lower/
// Time Complexity : O(logn)
// Approach-> Binary Search lgaya aur guess k hisab se limit set kro.....aur phir return

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int search(int low, int high)
{
    // mid m integer k limit k liye
    int mid = low + (high - low) / 2;
    int ans = guess(mid);
    if (ans == 0)
        return mid;
    else if (ans == 1)
    {
        ans = search(mid + 1, high);
    }
    else
    {
        ans = search(1, mid - 1);
    }
    return ans;
}

int guessNumber(int n)
{
    int mid = n / 2;
    int ans = guess(n / 2);
    if (ans == 0)
        return n / 2;
    int final = search(1, n);
    return final;
}

int main()
{

    return 0;
}