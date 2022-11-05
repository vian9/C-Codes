// Link : https://www.codingninjas.com/codestudio/problems/majority-element_842495?topList=love-babbar-dsa-sheet-problems
// Time Complexity : O(nlogn)
// Approach-> Sort krdia and then freq linear time mein compare krdia....agar usse freq jada h to update krdia
// Another approach could be ki hum ek vector bna lete and ussme frequency store krte elements ki....and finally usme max check
// krlete and ye O(n * logn)(logn for binary search in vector each time) time mein ho jata but space complexity would be O(n)....issue yhi tha vector k sth ki search krke index nhi nikal skte

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findMajorityElement(int arr[], int n)
{
    sort(arr, arr + n);
    int freq = 0;
    int a = arr[0];
    int ran = arr[0];
    int tempfreq = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ran)
        {
            tempfreq++;
        }
        if (tempfreq > freq)
        {
            a = ran;
            freq = tempfreq;
        }
        if (arr[i] != ran)
        {
            ran = arr[i];
            tempfreq = 1;
        }
    }
    if (freq > n / 2)
    {
        return a;
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