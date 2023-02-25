// Link : https://leetcode.com/problems/can-place-flowers/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// bool canPlaceFlowers(vector<int> &flowerbed, int n)
// {
//     bool canPlace = true;
//     bool last = flowerbed[0];
//     for (int i = 1; i < flowerbed.size(); i++)
//     {
//         if (flowerbed[i] !=)
//     }
//     return canPlace;
// }

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