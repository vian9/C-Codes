// Link : https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
// Time Complexity : O(n)
// Approach-> Original and Cloned are same toh jb target k barabar original mein aayega tb hi cloned m bhi aayega just return

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
    if (!original)
    {
        return nullptr;
    }
    if (original->val == target->val)
    {
        return cloned;
    }

    if (original->left)
    {
        TreeNode *leftNode = getTargetCopy(original->left, cloned->left, target);
        if (leftNode)
        {
            return leftNode;
        }
    }
    if (original->right)
    {
        TreeNode *rightNode = getTargetCopy(original->right, cloned->right, target);
        if (rightNode)
        {
            return rightNode;
        }
    }
    return nullptr;
}

int main()
{

    return 0;
}