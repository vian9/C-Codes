// Link : https://www.codingninjas.com/codestudio/problems/search-in-the-array_1116099?topList=love-babbar-dsa-sheet-problems
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> searchInTheArray(vector<int> &arr, vector<int> &queries, int n, int q)
{
    vector<int> sum(q, 0);
    // array is already sorted
    int sumtotal = 0;
    int j = 0;
    int i = 0;
    for (int i = 0; i < q; i++)
    {
        if (arr[j] <= queries[i] && j < n)
        {
            sumtotal += arr[j];
            j++;
        }
        else if (arr[i] > queries[i])
        {
            sum[j - 1] = sumtotal;
            j++;
        }
    }

    return sum;
}

int main()
{

    return 0;
}