// Link : https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
// Time Complexity : O(n)
// Approach-> Phle sbko count krke list bnalo.....aur then select krte jao.....and finally greedy choice lene h toh
// 3 se divide + 3 se rem will be val

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minimumRounds(vector<int> &tasks)
{
    unordered_map<int, int> count;
    for (int i = 0; i < tasks.size(); i++)
    {
        count[tasks[i]]++;
    }

    int val = 0;
    for (auto &i : count)
    {
        if (i.second < 2)
            return -1;
        if (i.second == 2)
            val++;
        if (i.second == 3)
            val++;
        if (i.second > 3)
        {
            int dig = i.second / 3;
            int rem = i.second % 3;
            if (rem != 0)
                val++;
            val += dig;
        }
    }
    return val;
}

int main()
{

    return 0;
}