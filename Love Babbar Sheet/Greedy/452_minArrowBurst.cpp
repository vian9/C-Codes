// Link : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Time Complexity : O(n)
// Approach-> Sort as per the first coordinate and now ab last point sbka lo and if in conflict toh arrow nhi otherwise arrow

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Greedy is always like phle sort kro and then choose kro

int findMinArrowShots(vector<vector<int>> &points)
{
    // Sort ascending m direct kro toh woh row wise hi first item se krdega
    sort(points.begin(), points.end());
    // for first ballon
    int arrow = 1;
    // hume check krna h kahan conflict horha h....jahan conflict h uske liye last k end > next k start
    int lastpoint = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
        // if not in conflict
        if (points[i][0] > lastpoint)
        {
            arrow++;
            // lastpoint updated
            lastpoint = points[i][1];
        }
        // agar conflict m aarha h ye ballon toh lastpoint update krenge na
        lastpoint = min(points[i][1], lastpoint);
    }
    return arrow;
}

int main()
{

    return 0;
}