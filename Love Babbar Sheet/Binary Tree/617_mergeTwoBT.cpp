// Link : https://leetcode.com/problems/merge-two-binary-trees/
// Time Complexity : O(n)
// Approach-> Phle root ka value update aur phir left aur right lagado

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    // Base Case sahi se rkho
    if (!root1 && !root2)
        return nullptr;
    else if (root1 && !root2)
        return root1;
    else if (!root1 && root2)
        return root2;

    // Values merge krdo
    root1->val = root1->val + root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

int main()
{

    return 0;
}