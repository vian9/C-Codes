// Link : https://practice.geeksforgeeks.org/problems/6e63df6d2ebdf6408a9b364128bb1123b5b13450/1
// Time Complexity : O(n)
// Approach-> Map m daalo and check wo item repeat na horha ho and then return incremented value.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long int minIncrements(vector<int> arr, int N)
{
    unordered_map<int, int> freq;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (freq.count(arr[i]) > 0)
        {
            int j = 1;
            while (freq.count(arr[i] + j) > 0)
            {
                j++;
            }
            freq[arr[i] + j]++;
            count += j;
        }
        else
        {
            freq[arr[i]]++;
        }
    }
    return count;
}

int main()
{

    return 0;
}