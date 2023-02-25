// Link : https://leetcode.com/problems/ipo/
// Time Complexity : O(nlogn)
// Approach-> Phle sort krdo on basis of capital
// Ab k times ko loop chalao nd pick krte jao jo jo le skte ho priority quque mein
// nd uska top ab lete jao nd do this until k times na ho jaye ya priority queue is empty mtlb aage nhi pick kr skte

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    // Capital k basis pr sort krdo
    vector<pair<int, int>> projects;
    // initial project bhi isse loop m choose krlenge
    // Isme profit k basis pr dalte jayenge
    priority_queue<int> pq;
    // final Ans will be updated w
    for (int i = 0; i < profits.size(); i++)
    {
        vt.push_back({capital[i], profits[i]});
    }
    sort(projects.begin(), projects.end());
    // Minimum capital se start krne k liye
    int ptr = 0;
    for (int i = 0; i < k; i++)
    {
        while (ptr < profits.size() && projects[ptr].first <= w)
        {
            pq.push(projects[ptr++].second);
        }

        // Agar pq empty to exit krlo...kuuki ab sav bada hoga
        if (pq.empty())
            break;
        // Weight mein bs wo while wale se highest wla lenge...aur ab aage k loop se continue krenge
        w += pq.top();
        pq.pop();
    }

    return w;
}

int main()
{

    return 0;
}