// Link : https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Time Complexity : O(n)
// Approach-> Check agar slope same hai toh straight line hoga......either slope 0 or infinie k alag case hoga to handle

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    // check for slope
    // coordinates size > 2 given

    // Method 1 ... bas cases ko itna likhna parrha bcoz we are dividing.....just multily and ab 0 hone se farqnhi prega
    double nativeY = (coordinates[1][1] - coordinates[0][1]);
    double nativeX = (coordinates[1][0] - coordinates[0][0]);

    for (int i = 1; i < coordinates.size(); i++)
    {
        double num = (coordinates[i][1] - coordinates[i - 1][1]);
        double denom = (coordinates[i][0] - coordinates[i - 1][0]);
        // y2-y1 * x1-x0 = y1-y0 * x2-x1
        if (num * nativeX != denom * nativeY)
        {
            return false;
        }
    }

    return true;

    // Method 2 by checking whether slope is 0 or infinite
    if ((coordinates[1][0] - coordinates[0][0]) != 0)
    {
        // double kuuki 0.5 is also a slope and not equal to 0
        double slope = 0;
        if (coordinates[1][1] - coordinates[0][1] != 0)
        {
            slope = ((double)(coordinates[1][1] - coordinates[0][1]) / (double)(coordinates[1][0] - coordinates[0][0]));
        }
        else
        {
            slope = 0;
        }

        for (int i = 1; i < coordinates.size(); i++)
        {
            double num = (coordinates[i][1] - coordinates[i - 1][1]);
            double denom = (coordinates[i][0] - coordinates[i - 1][0]);
            if (denom != 0)
            {
                if (slope != 0)
                {
                    if (num == 0)
                    {
                        return false;
                    }
                    else
                    {
                        if (num / denom != slope)
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    if (num != 0)
                    {
                        cout << i;
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        for (int i = 1; i < coordinates.size(); i++)
        {
            if (coordinates[i][0] != coordinates[i - 1][0])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}