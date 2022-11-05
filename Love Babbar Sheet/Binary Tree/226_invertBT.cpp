// Link : https://leetcode.com/problems/invert-binary-tree/
// Time Complexity : O(n)
// Approach-> Jo Tree dia h uska symmetric tree bnana h....mtlb hmare new tree ka left is old tree ka left

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

// DFS Traversal
void symmetricTree(TreeNode *root, TreeNode *newRoot)
{
    if (root == nullptr)
        return;

    // Bas BT mein ye dhyan rkho ki jiske aage aarow laga rhe ho wo null na ho
    // Yhan left node k liye right mein arrow laga rhe
    if (root->right != nullptr)
    {
        TreeNode *newLeft = new TreeNode(root->right->val);
        newRoot->left = newLeft;
    }
    if (root->left != nullptr)
    {
        TreeNode *newRight = new TreeNode(root->left->val);
        newRoot->right = newRight;
    }

    // Ab right tree bnane k liye left root ko call krdo
    symmetricTree(root->left, newRoot->right);
    symmetricTree(root->right, newRoot->left);
}

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return root;
    TreeNode *newRoot = new TreeNode(root->val);

    symmetricTree(root, newRoot);
    return newRoot;
}

int main()
{

    return 0;
}