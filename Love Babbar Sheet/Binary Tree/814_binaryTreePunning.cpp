// Link : https://leetcode.com/problems/binary-tree-pruning/
// Time Complexity : O(n)
// Approach-> Agar koi child nhi h aur root bhi 0 toh return null ....aur 1 hai to return root
// Agar child h....toh left and right ka lelo......ab left mein sav 0 aur root bhi 0 toh return false otherwise left ya right
// ko null bnado

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

bool isOne(TreeNode *root)
{
    if (!root)
    {
        return true;
    }
    // For root with no child
    if (!root->left && !root->right)
    {
        if (root->val)
            return true;
        return false;
    }
    // default false kuuki agar 0 hai and bas ek side k child h with 0 to return false kre
    bool leftCheck = false, rightCheck = false;
    if (root->left)
    {
        leftCheck = isOne(root->left);
    }
    if (root->right)
    {
        rightCheck = isOne(root->right);
    }
    if (root->val == 0)
    {
        if (!leftCheck && !rightCheck)
        {
            root->left = nullptr;
            root->right = nullptr;
            return false;
        }
        if (!leftCheck)
            root->left = nullptr;
        if (!rightCheck)
            root->right = nullptr;
    }
    if (root->val == 1)
    {
        if (!leftCheck)
            root->left = nullptr;
        if (!rightCheck)
            root->right = nullptr;
    }
    return true;
}

TreeNode *pruneTree(TreeNode *root)
{
    if (!root)
        return root;

    bool check = isOne(root);
    if (!check)
    {
        return nullptr;
    }
    return root;
}

int main()
{

    return 0;
}