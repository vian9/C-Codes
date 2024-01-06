// Link : https://leetcode.com/problems/word-ladder-ii/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);
    queue<vector<string>> q;
    q.push(beginWord);
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 1;
    vector<vector<string>> ans;

    while (!q.empty())
    {
        vector<string> front = q.front();
        q.pop();

        if (front == endWord)
        {
            if (ans.size() == 0)
                ans.push_back(front);
            else if (ans.back().size() == front.size())
                ans.push_back(front);
        }

        // Agar jo level h usme utna hi words hoga....usse jda word h to level bada h to delete new words from set
        if (front.size() > level)
        {
            level++;
            for (auto it : usedOnLevel)
            {
                st.erase(it);
            }
        }
        string word = front.back();
        int len = word.length();
        for (int i = 0; i < len; i++)
        {
            char original = word[i];
            for (char j = 'a'; j <= 'z'; j++)
            {
                word[i] = j;
                if (st.count(word) > 0)
                {
                    // queue k liye daldia
                    front.push_back(word);
                    q.push(front);
                    // use hogya ye word
                    usedOnLevel.push_back(word);
                    // pop back for new word
                    front.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}

int main()
{

    return 0;
}