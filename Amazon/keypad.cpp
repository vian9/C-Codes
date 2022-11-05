// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool comp(int a, int b)
{
    return a > b;
}

int keyPad(string s)
{
    vector<int> keys = {9, 9, 8};
    unordered_map<char, int> freq;
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }
    vector<int> value;
    for (auto &i : freq)
    {
        value.push_back(i.second);
    }
    freq.clear();
    sort(value.begin(), value.begin() + value.size(), comp);

    int count = 0;
    for (int i = 0; i < value.size(); i++)
    {
        if (keys[0] > 0)
        {
            count += (value[i] * 1);
            keys[0]--;
        }
        else if (keys[1] > 0)
        {
            count += (value[i] * 2);
            keys[1]--;
        }
        else if (keys[2] > 0)
        {
            count += (value[i] * 3);
            keys[2]--;
        }
    }
    return count;
}

int keyPad(string s)
{
    vector<int> keys = {9, 9, 8};
    unordered_map<char, int> freq;
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }
    vector<int> value;
    for (auto &i : freq)
    {
        value.push_back(i.second);
    }
    freq.clear();
    sort(value.begin(), value.begin() + value.size(), comp);

    int count = 0;
    for (int i = 0; i < value.size(); i++)
    {
        if (keys[0] > 0)
        {
            count += (value[i] * 1);
            keys[0]--;
        }
        else if (keys[1] > 0)
        {
            count += (value[i] * 2);
            keys[1]--;
        }
        else if (keys[2] > 0)
        {
            count += (value[i] * 3);
            keys[2]--;
        }
    }
    return count;
}