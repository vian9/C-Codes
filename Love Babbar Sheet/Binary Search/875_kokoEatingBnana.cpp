// Link : https://leetcode.com/problems/koko-eating-bananas/
// Time Complexity : O(nlogm)
// Approach-> Dekho...min rate = 1 and maxRate hoga jo max no in pile h
// Ab binary search se koi rate uthao and will eat up function ko dedo ki kha payega ya nhi

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// min integer such that sav kha jaye
bool willEatUp(vector<int> &piles, int h, int mid)
{
    double count = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        count += (piles[i] / mid);
        int rem = piles[i] % mid;
        if (rem != 0)
            count++;
    }
    if (count <= h)
        return true;
    return false;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int minEatingRate = 1;
    int maxEatingRate = *max_element(piles.begin(), piles.end());

    while (minEatingRate <= maxEatingRate)
    {
        int mid = (maxEatingRate - minEatingRate) / 2 + minEatingRate;
        if (willEatUp(piles, h, mid))
        {
            maxEatingRate = mid - 1;
        }
        else
        {
            minEatingRate = mid + 1;
        }
    }
    return minEatingRate;
}

int main()
{

    return 0;
}