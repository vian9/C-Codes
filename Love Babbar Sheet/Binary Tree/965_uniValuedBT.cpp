// Link : https://leetcode.com/problems/univalued-binary-tree/
// Time Complexity : O(n)
// Approach-> Phle root aur value daldo aur call krdo left and right and check for if val is same

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

bool checkTree(TreeNode *root, int vall)
{
    if (root == nullptr)
    {
        return true;
    }
    if (!root->left && !root->right)
    {
        if (root->val == vall)
            return true;
        else
            return false;
    }

    if (root->val != vall)
        return false;

    if (root->left)
    {
        if (!checkTree(root->left, vall))
            return false;
    }
    if (root->right)
    {
        if (!checkTree(root->right, vall))
            return false;
    }

    return true;
}

bool isUnivalTree(TreeNode *root)
{
    if (!root)
    {
        return true;
    }

    return checkTree(root, root->val);
}

int main()
{

    return 0;
}