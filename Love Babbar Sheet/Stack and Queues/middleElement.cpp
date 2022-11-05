// Link : https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/
// Time Complexity : O(n) in worst case
// Approach-> Count 0 se lia and usse aage badhate gye recursively tbtk count half k equal nhi hua
// and pop krke recursive call k baad push krdo.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void mid(stack<int> &s, int count, int size)
{
    if (count == size / 2)
    {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    mid(s, count + 1, size);
    s.push(num);
}

void deleteMid(stack<int> &s, int sizeOfStack)
{
    int count = 0;
    mid(s, count, sizeOfStack);
}

int main()
{

    return 0;
}