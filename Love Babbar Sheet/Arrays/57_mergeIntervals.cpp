// Link : https://leetcode.com/problems/insert-interval/description/
// Time Complexity : O(n)
// Approach-> Agar range se phle to push....range ke baad to push and conflict to common

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    // ye for loop in vector
    for (auto &&i : intervals)
    {
        // if start iske baad k hai and end bhi
        if (i[1] < newInterval[0])
            ans.push_back(i);
        // agar end se phle hai to push new Interval and update newInterval as i
        else if (i[0] > newInterval[1])
        {
            ans.push_back(newInterval);
            newInterval = i;
        }
        else
        {
            // conflict m common wla daaldo
            newInterval[0] = min(i[0], newInterval[0]);
            newInterval[1] = max(i[1], newInterval[1]);
        }
    }
    ans.push_back(newInterval);
    return ans;
}

int main()
{

    return 0;
}