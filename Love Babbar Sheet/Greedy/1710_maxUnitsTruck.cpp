// Link : https://leetcode.com/problems/maximum-units-on-a-truck/
// Time Complexity : O(nlogn)
// Approach-> Sort krdo by max unit per box se and then greedy se dalte jao

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
    // Static lgana is imp for Leetcode
    static bool compare(vector<int> v1, vector<int> v2)
    {
        return v1[1] > v2[1];
    }

public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        // Max unit per box pr sort krdia
        sort(boxTypes.begin(), boxTypes.end(), compare);
        // ab box ko pick krenge and unit lenge
        int units = 0;
        int boxes = 0;
        for (int i = 0; i < boxTypes.size(); i++)
        {
            if (truckSize == 0)
                break;
            if (truckSize >= boxTypes[i][0])
                boxes = boxTypes[i][0];
            else
                boxes = truckSize;
            truckSize -= boxes;
            units += boxes * boxTypes[i][1];
        }
        return units;
    }
};

int main()
{

    return 0;
}