// Link : https://leetcode.com/problems/search-in-a-binary-search-tree/
// Time Complexity : O(n/2)
// Approach-> Agar root k barabar h to thik....otherwise root->left se chota h to left mein call kro otherwise right mein

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

TreeNode *searchBST(TreeNode *root, int val)
{
    if (!root)
    {
        return null;
    }

    if (root->val == val)
    {
        return root;
    }

    if (root->val > val)
    {
        if (root->left)
        {
            return searchBST(root->left, val);
        }
    }
    if (root->val < val)
    {
        if (root->right)
        {
            return searchBST(root->right, val);
        }
    }
    return null;
}

int main()
{

    return 0;
}