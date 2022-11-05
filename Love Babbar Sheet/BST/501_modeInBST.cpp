// Link : https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

// map k bina krna h and even stack queue bhi nhi....count maintain krna hoga
int max = 0;
void check(unordered_map<int, int> &freq, TreeNode *root)
{
    if (!root)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        freq[root->val]++;
        if (freq[root->val] >= max)
            max = freq[root->val];
        return;
    }

    if (root->left)
    {
        check(freq, root->left);
    }
    if (root->right)
    {
        check(freq, root->right);
    }
    return;
}

vector<int> findMode(TreeNode *root)
{
    if (!root)
    {
        return {};
    }
    unordered_map<int, int> freq;
    check(freq, root);
    vector<int> ans;
    for (auto &it : freq)
    {
        if (it.second == max)
            ans.push_back(it.first);
    }
    return ans;
}

int main()
{

    return 0;
}