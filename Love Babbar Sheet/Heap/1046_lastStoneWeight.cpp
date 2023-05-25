// Link : https://leetcode.com/problems/last-stone-weight/
// Time Complexity : O(n)
// Approach-> Saare stones ko heap m daldo and ab jo 2 top pr ho usse clash krke dekhlo kya niklega

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int lastStoneWeight(vector<int> &stones)
{
    int n = stones.size();
    if (n == 0)
    {
        return 0;
    }
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(stones[i]);
    }

    while (pq.size() > 1)
    {
        int val1 = pq.top();
        pq.pop();
        int val2 = pq.top();
        pq.pop();
        if (val1 > val2)
        {
            pq.push(val1 - val2);
        }
        else if (val1 < val2)
        {
            pq.push(val2 - val1);
        }
    }
    if (!pq.empty())
        return pq.top();
    else
        return 0;
}

int main()
{

    return 0;
}