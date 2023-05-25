// Link : https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
// Time Complexity : O(n)
// Approach-> Total odd and even count krlo and jo max h uske position pr shift krdo and then cost is 1

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minCostToMoveChips(vector<int> &position)
{
    int evenCnt = 0;
    int oddCnt = 0;
    // Dekho logic bs whi h ki even and odd count krdo....ab bs koi ek jagah shift hoga uske hi cost hoga....ab even to even ya odd to odd ka cost nhi h bs jb even to odd h ya vice versa tb cost h
    for (int i = 0; i < position.size(); i++)
    {
        if (position[i] % 2 == 0)
            evenCnt++;
        else
            oddCnt++;
    }
    return min(evenCnt, oddCnt);
}

int main()
{

    return 0;
}