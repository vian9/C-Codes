// VVI
// Link : https://leetcode.com/problems/merge-sorted-array/
// Time Complexity : O(m+n)
// Approach-> Isme bs wo index k dhyan rkhna h baaki concept whi h merge sort wla

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // ind last se bhar rhe
    int ind = m + n - 1, end1 = m - 1, end2 = n - 1;
    while (end1 >= 0 && end2 >= 0)
    {
        // agar 2nd wla bda h to wo bharo
        if (nums1[end1] <= nums2[end2])
        {
            nums1[ind] = nums2[end2];
            end2--;
            ind--;
        }
        // wrna first se bharo
        else
        {
            nums1[ind] = nums1[end1];
            end1--;
            ind--;
        }
    }

    // Ab remaining wla bs 2nd array rhega usse bharlo
    while (end2 >= 0)
    {
        nums1[ind] = nums2[end2];
        end2--;
        ind--;
    }
}

int main()
{

    return 0;
}