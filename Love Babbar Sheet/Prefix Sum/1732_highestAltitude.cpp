// Link : https://leetcode.com/problems/find-the-highest-altitude/
// Time Complexity : O(n)
// Approach-> Just ek max lelia and usme update krte jao values

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int largestAltitude(vector<int> &gain)
{
    int maxi = 0;

    int prev = 0;
    for (int i = 0; i < gain.size(); i++)
    {
        prev += gain[i];
        maxi = max(prev, maxi);
    }
    return maxi;
}

int main()
{

    return 0;
}