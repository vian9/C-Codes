// Link : https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
// Time Complexity : O(n)
// Approach-> Check for agar x ya y barabar horha hai....agar haa toh check min dist se chota h to idex update and return

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int nearestValidPoint(int x, int y, vector<vector<int>> &points)
{
    int min = INT_MAX;
    int index = -1;
    for (int i = 0; i < points.size(); i++)
    {
        if (x == points[i][0] || y == points[i][1])
        {
            if (x == points[i][0])
            {
                if (min > abs(points[i][1] - y))
                {
                    index = i;
                    min = abs(points[i][1] - y);
                }
            }
            else if (y == points[i][1])
            {
                if (min > abs(points[i][0] - x))
                {
                    index = i;
                    min = abs(points[i][0] - x);
                }
            }
        }
    }
    return index;
}

int main()
{

    return 0;
}