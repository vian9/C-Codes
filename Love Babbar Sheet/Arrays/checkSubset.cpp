// Link : https://www.codingninjas.com/codestudio/problems/check-subset_762948?topList=love-babbar-dsa-sheet-problems
// Link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    sort(arr1.begin(), arr1.begin() + n);
    sort(arr2.begin(), arr2.begin() + m);
    for (int i = 0; i < m; i++)
    {
        int val = arr2[i];
        int low = lower_bound(arr1.begin(), arr1.begin() + n, val);
        if (arr1[low] == arr2[i])
        {
            arr1[low] = -1;
            arr2[i] == -1;
        }
        else
        {
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
    }
    return 0;
}