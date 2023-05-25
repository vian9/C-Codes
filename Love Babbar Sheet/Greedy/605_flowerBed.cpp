// Link : https://leetcode.com/problems/can-place-flowers/
// Time Complexity : O(n)
// Approach-> Agar bagal m 0 h to dalte jao flowerbed.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Simple greedy ki bagal agal m 0 and current bhi 0 to 1 krdo and flower daldo
// bs Edge case dekhlo and side i =0 and i = n-1 k dekhlo
bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int count = 0;
    if (n > flowerbed.size())
        return false;
    if (n == 0)
        return true;
    if (flowerbed.size() == 1)
    {
        if (flowerbed[0] == 0)
            return true;
        else
            return false;
    }
    for (int i = 0; i < flowerbed.size(); i++)
    {
        if ((i == 0 && flowerbed[i] == 0) && flowerbed[i + 1] == 0)
        {
            flowerbed[i] = 1;
            count++;
        }
        else if ((i == flowerbed.size() - 1 && flowerbed[i - 1] == 0) && flowerbed[i] == 0)
        {
            flowerbed[i] = 1;
            count++;
        }
        else if ((i > 0 && i < flowerbed.size() - 1))
        {
            if ((flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0))
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        if (count == n)
            return true;
    }
    if (count == n)
        return true;
    return false;
}

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    if (n > flowerbed.size())
    {
        return false;
    }
    // If n=0 to hmesa true
    if (n == 0)
        return true;
    // Agar size == 1 to bhi return true
    if (flowerbed.size() == 1)
    {
        if (flowerbed[0] == 0 && n == 1)
            return true;
        else
            return false;
    }
    int count = 0;
    for (int i = 0; i < flowerbed.size(); i++)
    {
        if (i == 0 || i == flowerbed.size() - 1)
        {
            if (i == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
            else if (i == flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        else
        {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        if (count == n)
        {
            return true;
        }
    }
    if (count == n)
        return true;
    return false;
}

int main()
{
    int length = 2909;
    int width = 3968;
    int height = 3272;
    const unsigned int MOD = 1000000007;
    long long vol = (length % MOD) * (width % MOD) * (height % MOD) % MOD;
    cout << vol;
    return 0;
}