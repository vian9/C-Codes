#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void change()
{
}

int minimumSeconds(vector<int> &nums)
{

    unordered_map<int, int> mp;
    int val = -1;
    int freq = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
        if (freq <= mp[nums[i]])
        {
            freq = mp[nums[i]];
            val = nums[i];
        }
    }
    int n = nums.size();
    int count = 0;
    freq = -1;
    while (freq != 1)
    {
        set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        freq = st.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
                continue;
            else
            {
                if (nums[(i - 1 + n) % n] == val || nums[(i + 1) % n] == val)
                    nums[i] = val;
            }
        }
        count++;
    }
    return count;
}

int main()
{
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto num : mp)
    {
        pq.push({num.first, num.second});
    }

    int seconds = 0;
    while (pq.size() > 1)
    {
        int num = pq.top().first;
        int frequency = pq.top().second;
        pq.pop();

        if (frequency == 1)
        {
            return seconds;
        }
        else
        {
            // Replace all occurrences of the element with the highest frequency with a new distinct element.
            int new_num = num + seconds;
            for (int i = 0; i < frequency; i++)
            {
                nums[i] = new_num;
            }

            seconds++;
        }
    }

    return seconds;

    return 0;
}