// Link : https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/
// Time Complexity : O(1)
// Approach-> Firsrt digit can have 0,1,2...waise hi second depends on first...so make cases

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string maximumTime(string time)
{
    // max time we can get
    // Agar first nhi h and second hai ya nhi uske basis pr
    if (time[0] == '?')
    {
        if (time[1] <= '3' || time[1] == '?')
        {
            time[0] = '2';
        }
        else
        {
            time[0] = '1';
        }
    }
    // Ab first k time pr ye depend krega
    if (time[1] == '?')
    {
        if (time[0] == '2')
        {
            time[1] = '3';
        }
        else
        {
            time[1] = '9';
        }
    }
    // Time 3 ko max 5 ho skta
    if (time[3] == '?')
    {
        time[3] = '5';
    }
    // Last can be max 9
    if (time[4] == '?')
    {
        time[4] = '9';
    }
    return time;
}

int main()
{

    return 0;
}