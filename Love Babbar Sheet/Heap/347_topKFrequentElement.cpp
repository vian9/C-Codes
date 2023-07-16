// Link : https://leetcode.com/problems/top-k-frequent-elements/
// Time Complexity : O()
// Approach-> Understand the language of ques....it says find the k elements with most frequency

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> topKFrequent(vector<int> &nums, int k)
{
    int n = nums.size();
    // Map m saara elements and freq daaldia
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    vector<int> ans;
    // maxHeap lelo and usme pair dalo map ka jisme first mein frequency and second m element dalo as by default priority queue will sort by first i.e. frequency
    priority_queue<pair<int, int>> pq;
    for (auto i : mp)
    {
        pq.push({i.second, i.first});
    }

    // Ab top k elements nikallo by second element
    while (k > 0)
    {
        ans.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    return ans;
}

int main()
{

    return 0;
}