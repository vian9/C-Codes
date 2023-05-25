// Link : https://leetcode.com/problems/boats-to-save-people/
// Time Complexity : O(nlogn)
// Approach-> Sort krdo and last se bharna start kro and start se tb badho jbtk ya match na krjaye limit tk

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int numRescueBoats(vector<int> &people, int limit)
{
    int count = 0;
    sort(people.begin(), people.end());
    int start = 0;
    int end = people.size() - 1;
    while (start <= end)
    {
        // Agar start wla lggya end se limit m to rkhlo start++;
        if (people[start] + people[end] <= limit)
        {
            start++;
        }
        // otherwise end se peeche chlte jao
        end--;
        count++;
    }

    return count;
}

int main()
{

    return 0;
}