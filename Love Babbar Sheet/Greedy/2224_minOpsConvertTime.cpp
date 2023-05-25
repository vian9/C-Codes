// Link : https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/
// Time Complexity : O(1)
// Approach-> Saare hours and mins nikalo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int convertTime(string current, string correct)
{
    // current and correct hour and min nikallo
    int curHour = 0;
    curHour = (current[0] - '0') * 10 + (current[1] - '0');
    int corHour = 0;
    corHour = (correct[0] - '0') * 10 + (correct[1] - '0');
    int diffHour = corHour - curHour;
    int count = 0;
    int curMin = 0;
    curMin = (current[3] - '0') * 10 + (current[4] - '0');
    int corMin = 0;
    corMin = (correct[3] - '0') * 10 + (correct[4] - '0');
    int diffMin = corMin - curMin;
    // If diffMin is less than 0 to hour se 1 minus kro and ab 60 se diffMin nikallo
    if (diffMin < 0)
    {
        diffHour -= 1;
        diffMin *= -1;
        diffMin = 60 - diffMin;
    }
    // Ab bs diffMin ko lelo kitna kitna se hoga
    count += diffHour;
    if (diffMin / 15 != 0)
    {
        int div = diffMin / 15;
        count += div;
        diffMin -= (15 * div);
    }
    if (diffMin / 5 != 0)
    {
        int div = diffMin / 5;
        count += div;
        diffMin -= (5 * div);
    }
    if (diffMin / 1 != 0)
    {
        int div = diffMin / 1;
        count += div;
        diffMin -= (1 * div);
    }
    return count;
}

int main()
{

    return 0;
}