// Link : https://leetcode.com/problems/first-bad-version/
// Time Complexity : O(logn)
// Approach-> Just mid lena sahi se sikho.....bas agar mid is bad version toh mid se chota check kro otherwise mid se bada
// Jabtak ki low > high na ho.....phir return low that's the base case nd return low whi first bad hoga.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int badVersion(int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid))
        {
            return badVersion(low, mid - 1);
        }
        else
        {
            return badVersion(mid + 1, high);
        }
    }
    // Base Case
    return low;
}
int firstBadVersion(int n)
{
    return badVersion(1, n);
}

int main()
{

    return 0;
}