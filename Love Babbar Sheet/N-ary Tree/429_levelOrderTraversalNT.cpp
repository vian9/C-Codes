// Link : https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Time Complexity : O(n)
// Approach-> Phle root ko daal dia usse level pr vector mein phir children ko call krdia

#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
#define ll long long int

void levelOrderAtK(Node *root, int level, vector<vector<int>> &ans)
{
    if (!root)
    {
        return;
    }

    if (level + 1 > ans.size())
    {
        ans.push_back({root->val});
    }
    else
    {
        ans[level].push_back(root->val);
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        levelOrderAtK(root->children[i], level + 1, ans);
    }
    return;
}

vector<vector<int>> levelOrder(Node *root)
{
    if (!root)
    {
        return {};
    }
    vector<vector<int>> ans;

    levelOrderAtK(root, 0, ans);
    return ans;
}

int main()
{

    return 0;
}