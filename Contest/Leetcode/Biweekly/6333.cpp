// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

int digLen(int num)
{
    int len = 0;
    if (num < 0)
    {
        len++;
        num = num * -1;
    }
    while (num > 0)
    {
        len++;
        num = num / 10;
    }
    return len;
}

vector<int> findColumnWidth(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<int> ans(col, 0);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans[j] = max(ans[j], digLen(grid[i][j]));
        }
    }

    return ans;
}

vector<long long> findPrefixScore(vector<int> &nums)
{
    vector<long long> ans(nums.size(), 0);
    int maxi = nums[0];
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
        ans[i] = nums[i] + maxi + sum;
        sum += ans[i];
    }
    return ans;
}

int sum depthFill(TreeNode *root, vector<vector<pair<int, pair<int, long long>>>> &nodess, int parent, int depth)
{
    if (root == nullptr)
    {
        return;
    }
    pair<int, int> curr;
    curr.first = parent;
    curr.second = root->val;
    if (nodess.size() < depth)
    {
        vector<pair<int, int>> ans;
        ans.push_back(curr);
        nodess.push_back(ans);
    }
    else
    {
        nodess[depth - 1].push_back(curr);
    }
    if (root->left)
    {
        depthFill(root->left, nodess, root->val, depth + 1);
    }
    if (root->right)
    {
        depthFill(root->right, nodess, root->val, depth + 1);
    }
}

TreeNode *fillNodes(TreeNode *root, vector<vector<pair<int, pair<int, long long>>>> &nodess, int depth, int parent)
{
    if (root == nullptr)
    {
        return root;
    }
    TreeNode *leftt;
    TreeNode *rightt;
    if (root->left)
    {
        leftt = fillNodes(root->left, nodess, depth + 1, root->val);
        root->left = leftt;
    }
    if (root->right)
    {
        rightt = fillNodes(root->right, nodess, depth + 1, root->val);
        root->right = rightt;
    }
    vector<pair<int, int>> curr = nodess[depth - 1];
    long long sum = 0;
    for (int i = 0; i < curr.size(); i++)
    {
        if (curr[i].first != parent)
        {
            sum += curr[i].second;
        }
    }
    root->val = sum;
    if (!root->left && !root->right)
    {
        return root;
    }
    return root;
}

TreeNode *replaceValueInTree(TreeNode *root)
{
    // main bfs se depth, parent and val and child sum nikal lu
    vector<vector<pair<int, pair<int, long long>>>> nodess = vector<vector<pair<int, pair<int, long long>>>>(1, vector<pair<int, pair<int, long long>>>(1, {-1, {0, 0}}));
    depthFill(root, nodess, -1, 1);
    return fillNodes(root, nodess, 1, -1);
}

long long depthFill(TreeNode *root, unordered_map<int, long long> &mp, vector<vector<int>> &parent, int parent, int depth)
{
    if (root == nullptr)
    {
        return;
    }
    if (parent.size() < depth)
    {
        vector<pair<int, int>> ans;
        ans.push_back(root->val);
        nodess.push_back(ans);
    }
    else
    {
        nodess[depth - 1].push_back(root->val);
    }
    long long leftSum = 0, rightSum = 0;
    if (root->left)
    {
        leftSum = depthFill(root->left, mp, parent, root->val, depth + 1);
    }
    if (root->right)
    {
        rightSum = depthFill(root->right, mp, parent, root->val, depth + 1);
    }
    mp[root->val] = leftSum + rightSum;
}

TreeNode *fillNodes(TreeNode *root, unordered_map<int, long long> &mp, vector<vector<int>> &parent, int depth, int parent)
{
    if (root == nullptr)
    {
        return root;
    }
    TreeNode *leftt;
    TreeNode *rightt;
    if (root->left)
    {
        leftt = fillNodes(root->left, mp, parent, depth + 1, root->val);
        root->left = leftt;
    }
    if (root->right)
    {
        rightt = fillNodes(root->right, mp, parent, depth + 1, root->val);
        root->right = rightt;
    }
    root->val = 0;
    if (depth >= 2)
    {
        vector<int> curr = parent[depth - 2];
        for (int i = 0; i < curr.size(); i++)
        {
            if (curr[i] != parent)
            {
                root->val += mp[curr[i]];
            }
        }
    }
    if (!root->left && !root->right)
    {
        return root;
    }
    return root;
}

TreeNode *replaceValueInTree(TreeNode *root)
{
    // main bfs se depth, parent and val nikal lu
    unordered_map<int, long long> mp;
    vector<vector<int>> parent;
    long long allsum = depthFill(root, mp, parent, -1, 1);
    return fillNodes(root, nodess, 1, -1);
}

int main()
{

    return 0;
}