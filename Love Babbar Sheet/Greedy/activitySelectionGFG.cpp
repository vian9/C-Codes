// Link : https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1
// Time Complexity : O()
// Approach-> Pairwise activity lelo and usme sort krdo end time se.....ab jb endTime se starttime bada h tb select krlo
// similar to N meetings in a room

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Function to find the maximum number of activities that can
// be performed by a single person.
int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<int, int>> activity;
    for (int i = 0; i < n; i++)
    {
        activity.push_back({end[i], start[i]});
    }

    sort(activity.begin(), activity.end());

    int count = 0;
    int lastEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (activity[i].second > lastEnd)
        {
            count++;
            lastEnd = activity[i].first;
        }
    }

    return count;
}

int main()
{

    return 0;
}