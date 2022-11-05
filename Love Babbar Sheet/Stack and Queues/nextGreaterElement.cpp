// VVI
// Link : https://leetcode.com/problems/next-greater-element-i/
// Link : https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// Time Complexity : O(n)
// Approach-> Stack use krna hoga
// Ab stack mein jo sbse top pr hoga woh min hoga (LIFO....jo bhi stack mein rhega jb right mein uska chota element h bada hota to nikl jata na next greater k sth) toh jbtk usse bada nhi milega tbtk stack clear nhi kr payenge
// Stack lelia and usme push krte gye and agar uska top se max wala condition match krta h to map mein daal dia nd phir pura stack wahan clear ho jayega jo bhi usse chota h wahan tk
// ab map mein saare element k greater ya -1 daal dia and phir map mein dhundhkr O(1) mein ek search se O(n) mein corresponding vector mein push krdia

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// LeetCode
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> greatr;
    unordered_map<int, int> result;
    greatr.push(nums2[0]);
    for (int i = 1; i < nums2.size(); i++)
    {
        if (greatr.empty())
        {
            greatr.push(nums2[i]);
            continue;
        }

        while (!greatr.empty() && greatr.top() < nums2[i])
        {
            result.insert({greatr.top(), nums2[i]});
            greatr.pop();
        }
        greatr.push(nums2[i]);
    }
    while (!greatr.empty())
    {
        result.insert({greatr.top(), -1});
        greatr.pop();
    }
    vector<int> ans(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); i++)
    {
        ans[i] = result.at(nums1[i]);
    }

    return ans;
}

// GeeksforGeeks - O(n)....Stack lelia and usme push krte gye and agar uska top se match krta h to map mein daal dia
// ab map mein saare element k greater ya -1 daal dia and phir map mein dhundhkr O(1) mein ek search se O(n) mein corresponding vector mein push krdia

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> greatr;
    unordered_map<long long, long long> result;
    greatr.push(arr[0]);
    for (long long i = 1; i < n; i++)
    {
        if (greatr.empty())
        {
            greatr.push(arr[i]);
            continue;
        }

        while (!greatr.empty() && greatr.top() < arr[i])
        {
            result.insert({greatr.top(), arr[i]});
            greatr.pop();
        }
        greatr.push(arr[i]);
    }
    while (!greatr.empty())
    {
        result.insert({greatr.top(), -1});
        greatr.pop();
    }
    vector<long long> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        ans[i] = result.at(arr[i]);
    }

    return ans;
}

int main()
{

    return 0;
}