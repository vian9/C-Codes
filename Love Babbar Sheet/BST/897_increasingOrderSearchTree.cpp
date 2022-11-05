// Link : https://leetcode.com/problems/increasing-order-search-tree/
// Time Complexity : O(n)
// Approach-> Inorder list lelia aur new Tree bnadia

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

// Method 2 is recursively arrange but how ...?

// method 1 i am getting in mind is to just take a vector and fill inorder....that will have sorted value and then make tree
void inorderTraversal(TreeNode *root, vector<int> &ans)
{
    // Base Case
    if (!root)
    {
        return;
    }

    // root null bhi call krrhe to base case pr jake hit horha
    inorderTraversal(root->left, ans);
    ans.push_back(root->val);
    inorderTraversal(root->right, ans);
}

TreeNode *increasingBST(TreeNode *root)
{
    if (!root)
    {
        return nullptr;
    }

    vector<int> nodes;
    inorderTraversal(root, nodes);
    TreeNode *newRoot = new TreeNode(nodes[0]);
    TreeNode *temp = newRoot;
    for (int i = 1; i < nodes.size(); i++)
    {
        TreeNode *newNode = new TreeNode(nodes[i]);
        temp->right = newNode;
        temp = newNode;
    }
    return newRoot;
}

int main()
{

    return 0;
}