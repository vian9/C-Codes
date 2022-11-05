// Link : https://www.codingninjas.com/codestudio/problems/subarrays-with-zero-sum_3161876?topList=love-babbar-dsa-sheet-problems
// Time Complexity : O(n ^ 3) for M-1.....O(n^2) for M-2
// Approach-> Saara subarray nikalkr value check krrhe ki sum zero horha ye h brute force method (M-1 here)
// Optimal solution hum ending point pr iterate krte gye and subsequence pr sum dekhte gye....hume subarray print nhi
// krwana tha bas check krna tha wo to 2 loop se hi ho jaarha h
// Another method can be through map

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int countSubarrays(int n, vector<int> &arr)
{
    // Method 1 .....3 loop lagakr check krrhe ki sum zero horha
    //     int count = 0;
    //      for (int i = 0; i < n; i++)
    //      {
    //          for (int j = i; j < n; j++)
    //          {
    //              int sum = 0;
    //              for (int k = i; k <= j; k++)
    //              {
    //                  sum += arr[k];
    //              }
    //              if (sum == 0)
    //              {
    //                  count++;
    //              }
    //          }
    //      }
    //      return count;

    // Method 2....
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{

    return 0;
}