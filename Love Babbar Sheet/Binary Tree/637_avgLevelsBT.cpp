// Link : https://leetcode.com/problems/average-of-levels-in-binary-tree/
// Time Complexity : O(n)
// Approach-> Ek vector lelia pair ka jisme first will store the avg value and second will ki kitna nodes aaya at Kth level
// Ab usse actual value nikal kr aur phir no of nodes increase krdo aur vector update krke call left and right

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

void avgAtKLevels(TreeNode *root, int k, vector<pair<double, int>> &ans)
{
    if (!root)
    {
        return;
    }
    int n = ans.size();
    if (n < k + 1)
        ans.push_back({0, 0});

    // Total = avg Value * total no of items
    double total = ans[k].second * ans[k].first + root->val;
    // Ab avg = total / total no of items
    total = total / (ans[k].second + 1);
    ans[k].first = total;
    ans[k].second = ans[k].second + 1;
    avgAtKLevels(root->left, k + 1, ans);
    avgAtKLevels(root->right, k + 1, ans);
}

vector<double> averageOfLevels(TreeNode *root)
{
    if (!root)
    {
        return {0};
    }

    vector<pair<double, int>> ans;
    avgAtKLevels(root, 0, ans);
    vector<double> result;
    for (int i = 0; i < ans.size(); i++)
    {
        result.push_back(ans[i].first);
    }
    return result;
}

int main()
{

    return 0;
}