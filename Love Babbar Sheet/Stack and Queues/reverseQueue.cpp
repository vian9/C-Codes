// Link : https://practice.geeksforgeeks.org/problems/queue-reversal/1
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int num = q.front();
    q.pop();
    reverse(q);
    q.push(num);
}
queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}

int main()
{

    return 0;
}