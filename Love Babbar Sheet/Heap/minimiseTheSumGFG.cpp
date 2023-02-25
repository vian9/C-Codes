// Link : https://practice.geeksforgeeks.org/problems/86e609332c9ef4f6b8aa79db11a6c0808c4a1bca/1
// Time Complexity : O(n)
// Approach-> Bss yeh dhyan rkhna h size == 1 jbtk na ho tbtk ye chlana h.....2 values lo usko pop krke uska sum psuh kro
// and ab uska sum add krte jao.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minimizeSum(int N, vector<int> arr)
{
    priority_queue<int, vector<int>, greater<int>> mini;
    for (int i = 0; i < N; i++)
    {
        mini.push(arr[i]);
    }
    int sum = 0;
    while (mini.size() > 1)
    {
        int front1 = mini.top();
        mini.pop();
        int front2 = mini.top();
        mini.pop();
        sum += (front1 + front2);
        mini.push(front1 + front2);
    }
    return sum;
}

int main()
{

    return 0;
}