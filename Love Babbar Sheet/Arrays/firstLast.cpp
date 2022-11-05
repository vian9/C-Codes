// Link : https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?topList=love-babbar-dsa-sheet-problems
// Time Complexity : O(n)
// Approach-> Phle iterate krke 1st index nikal lia and phir last index

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    pair<int, int> p1;
    int i = -1;
    int j = -1;
    for (int t = 0; t < n; t++)
    {
        if (arr[t] == k)
        {
            i = t;
            break;
        }
    }
    if (i != -1)
    {
        for (int t = i; t < n; t++)
        {
            if (arr[t] == k)
            {
                j = t;
            }
            if (arr[t] != k)
            {
                break;
            }
        }
    }

    p1.first = i;
    p1.second = j;
    return p1;
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