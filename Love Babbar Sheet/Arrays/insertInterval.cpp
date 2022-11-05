// VVI
// Link : https://leetcode.com/problems/insert-interval/
// Time Complexity : O(log n)
// Approach-> Phle Binary search krke start and end nikalo.....phir start se aage wla push kro phir merge intervals wla
// Start ya newStart mein min wla lenge waise hi end nd newEnd mein max wla....phir end k baad wla push kro....in this way u can.
// Binary search kaise kia wo dhyan rkho

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    int n = intervals.size();
    int start = newInterval[0];
    int end = newInterval[1];
    int newStart = 0;
    int newEnd = 0;
    if (!n)
    {
        ans.push_back(newInterval);
        return ans;
    }
    if (intervals[n - 1][1] < start)
    {
        intervals.push_back({start, end});
        return intervals;
    }
    if (intervals[0][0] > end)
    {
        intervals.insert(intervals.begin(), {start, end});
        return intervals;
    }
    // Using Binary Search to find the smallest start and end
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // Jaise hi intervals k last jada hota h to high kaam krenge and kaam hota h to low jada krenge...
        //  jaise hi low > high mtlb low is the ans
        if (intervals[mid][1] < start)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    newStart = low;
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (intervals[mid][0] > end)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    newEnd = high;
    for (int i = 0; i < newStart; i++)
    {
        ans.push_back({intervals[i][0], intervals[i][1]});
    }
    newStart = min(intervals[newStart][0], start);
    newEnd = max(intervals[newEnd][1], end);
    ans.push_back({newStart, newEnd});
    for (int i = high + 1; i < n; i++)
    {
        ans.push_back({intervals[i][0], intervals[i][1]});
    }

    return ans;
}

int main()
{

    return 0;
}