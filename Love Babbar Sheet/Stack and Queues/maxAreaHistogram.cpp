// Link : https://leetcode.com/problems/largest-rectangle-in-histogram/
// Link : https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// LeetCode
int largestRectangleArea(vector<int> &heights)
{
    stack<int> next;
    vector<int> left;
    vector<int> area;
    next.push(heights[0]);
    for (int i = 1; i < heights.size(); i++)
    {
        if (next.empty())
        {
            next.push(heights[i]);
            continue;
        }

        if (!next.empty() && next.top() <= heights[i])
        {
            next.push(heights[i]);
        }
    }
}

// GeeksforGeeks
long long getMaxArea(long long arr[], int n)
{
}

int main()
{

    return 0;
}