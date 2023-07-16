// Link : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// Time Complexity : O()
// Approach-> Similar to N Activities...bs isme end Time se sort krdo and jo end TIme k baad aarha usse activity ko hum kra skte h
// Constraints are 10^5

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Function to find the maximum number of meetings that can
// be performed in a meeting room.

int maxMeetings(int start[], int end[], int n)
{
    // Pairpise start and end time daldiye
    vector<pair<int, int>> ps;
    for (int i = 0; i < n; i++)
    {
        ps.push_back({end[i], start[i]});
    }
    // Sort using endtime taaki hume max activity mil ske jo jldi over horha ho
    sort(ps.begin(), ps.end());
    int count = 0;
    int endTime = -1;
    int startTime = -1;
    // AB pick those activities whose startTIme > endTIme of last
    for (int i = 0; i < n; i++)
    {
        int startTime = ps[i].second;
        if (startTime > endTime)
        {
            count++;
            endTime = ps[i].first;
        }
    }
    return count;
}

int main()
{

    return 0;
}