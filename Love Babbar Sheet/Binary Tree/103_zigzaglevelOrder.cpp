// Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Time Complexity : O(n)
// Approach-> Dekho phle root ko daal do nd ab level order traversal kro nd sbka height bhi dalte jao in queue
// Agar ab vector mein phle se stored h to access krke directly store kro otherwise new vector push krdo
// and finally reverse every 2nd vector

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<vector<int>> ans;
    bool isOrder = true;
    queue<TreeNode *> qt;
    qt.push(root);
    int k = 0;
    while (!qt.empty())
    {
        k = qt.size();
        vector<int> temp;
        for (int i = 0; i < k; i++)
        {
            TreeNode *front = qt.front();
            qt.pop();
            if (front != nullptr)
            {
                temp.push_back(front->val);
                if (front->left)
                    qt.push(front->left);
                if (front->right)
                    qt.push(front->right);
            }
        }
        if (isOrder)
            ans.push_back(temp);
        else
        {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        isOrder = !isOrder;
    }
    return ans;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    // Level order traversal krdo using BFS nd then alternate ko reverse krdo
    vector<vector<int>> ans;
    if (!root)
    {
        return ans;
    }
    queue<pair<TreeNode *, int>> qs;
    qs.push({root, 0});
    vector<int> roots(1, root->val);
    ans.push_back(roots);
    while (!qs.empty())
    {
        pair<TreeNode *, int> front = qs.front();
        qs.pop();
        if (ans.size() > front.second + 1)
        {
            if (front.first->left)
            {
                ans[front.second + 1].push_back(front.first->left->val);
                qs.push({front.first->left, front.second + 1});
            }
            if (front.first->right)
            {
                ans[front.second + 1].push_back(front.first->right->val);
                qs.push({front.first->right, front.second + 1});
            }
        }
        else
        {
            vector<int> temp;
            if (front.first->left)
            {
                temp.push_back(front.first->left->val);
                qs.push({front.first->left, front.second + 1});
            }
            if (front.first->right)
            {
                temp.push_back(front.first->right->val);
                qs.push({front.first->right, front.second + 1});
            }
            if (temp.size() > 0)
                ans.push_back(temp);
        }
    }
    vector<vector<int>> finalAns;
    int j = 1;
    for (auto &&i : ans)
    {
        vector<int> temp = i;
        if (j % 2 == 0)
            reverse(temp.begin(), temp.end());
        j++;
        finalAns.push_back(temp);
    }
    return finalAns;
}

int main()
{

    return 0;
}