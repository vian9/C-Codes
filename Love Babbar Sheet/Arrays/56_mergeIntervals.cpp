// Link : https://leetcode.com/problems/merge-intervals/
// Time Complexity : O(nlogn)
// Approach-> Sort krna hoga most importantly kuuki intervals kahin bhi aarha h....uske baad bs last element se compare

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    // Ye logic tbhi lga skte ho ki intervals last se overlap jb sorted ho
    sort(intervals.begin(), intervals.end());
    ans.push_back({intervals[0][0], intervals[0][1]});
    for (int i = 1; i < intervals.size(); i++)
    {
        int lastStart = ans[ans.size() - 1][0];
        int lastEnd = ans[ans.size() - 1][1];
        // Ab agar overlap krrha h to newStart and newEnd daaldo
        if (intervals[i][0] <= lastEnd)
        {
            ans[ans.size() - 1][0] = min(lastStart, intervals[i][0]);
            ans[ans.size() - 1][1] = max(lastEnd, intervals[i][1]);
        }
        else
        {
            ans.push_back({intervals[i][0], intervals[i][1]});
        }
    }
    return ans;
}

int main()
{

    return 0;
}