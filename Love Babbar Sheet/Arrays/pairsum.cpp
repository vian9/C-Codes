// Link: https://www.codingninjas.com/codestudio/problems/pair-sum_1171154?topList=love-babbar-dsa-sheet-problems
// Time : O(n)
// Approach -> sort krne na krne se faiyda nhi
// to check then ki kitna distinct pairs bna paarhe on addition.
// toh start ko x and prev ko y mana and usko add krte gya.....agar value jada to y-- kia taki uske barabar k close ho
// waise hi x pr operation lagaya.......mathematics similar to divide and conquer

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int pairSum(vector<int> &arr, int n, int target)
{
    int x = 0;
    int y = n - 1;
    int count = 0;
    while (x < y)
    {
        if ((arr[x] + arr[y]) == target)
        {
            count++;
            x++;
            y--;
        }
        else if ((arr[x] + arr[y]) > target)
        {
            y--;
        }
        else if ((arr[x] + arr[y]) < target)
        {
            x++;
        }
    }
    if (count > 0)
    {
        return count;
    }
    else
    {
        return -1;
    }
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