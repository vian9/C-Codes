// Link : https://leetcode.com/problems/word-ladder/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty())
    {
        string front = q.front().first;
        int step = q.front().second;
        q.pop();
        if (front == endWord)
            return step;
        int len = front.length();
        for (int i = 0; i < len; i++)
        {
            char original = front[i];
            for (char j = 'a'; j <= 'z'; j++)
            {
                front[i] = j;
                if (st.find(front) != st.end())
                {
                    st.erase(front);
                    q.push({front, step + 1});
                }
            }
            front[i] = original;
        }
    }
    return 0;
}

int main()
{

    return 0;
}