// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long pickGifts(vector<int> &gifts, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < gifts.size(); i++)
    {
        pq.push(gifts[i]);
    }
    while (k > 0)
    {
        int front = pq.top();
        pq.pop();
        int top = (int)sqrt(front);
        pq.push(top);
        k--;
    }
    long long ans = 0;
    while (!pq.empty())
    {
        int front = pq.top();
        pq.pop();
        ans += front;
    }
    return ans;
}

int main()
{

    return 0;
}