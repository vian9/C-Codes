// VVI
//  Link : https://leetcode.com/problems/sliding-window-maximum/
//  Time Complexity : O(n)
//  Approach-> Window size k rhega and hume usse se consider krke index deque mein daalenge
// deque is doubly ended queue......we will store index

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> comp;
    for (int i = 0; i < nums.size(); i++)
    {
        // Agar deque empty nhi h and front out of window h (k = 3, i =3, index 0 is out of bound) toh usse pop
        if (!comp.empty() && comp.front() == i - k)
        {
            comp.pop_front();
        }
        // Agar element back mein chota hai to pop krte jayenge
        while (!comp.empty() && nums[comp.back()] < nums[i])
        {
            comp.pop_back();
        }
        // Push the index woh back wale se chota hua phir bhi
        comp.push_back(i);
        // k-1 jaise hi i hoga uske baad window size k max nikalte jayega
        if (i >= k - 1)
        {
            ans.push_back(nums[comp.front()]);
        }
    }
    return ans;
}

int main()
{

    return 0;
}