// Link : https://leetcode.com/problems/range-sum-of-bst/
// Time Complexity : O(n)
// Approach-> Phle root ka val check krlo and left and right pr call krdo by checking low and high as bst hai to sequence hoga

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

int rangeSumBST(TreeNode *root, int low, int high)
{
    // Edge Case h
    if (!root)
    {
        return 0;
    }

    // Isme no need of base case as ussepr jayega hi nhi
    // Isme no need of checking nodes with no child as uspr jayega to bas root val return hoga jo ye if root->Val pr krrhe h
    int sum = 0;
    if (root->val >= low && root->val <= high)
    {
        sum = root->val;
    }

    if (root->left && low <= root->val)
        sum += rangeSumBST(root->left, low, high);

    if (root->right && high >= root->val)
        sum += rangeSumBST(root->right, low, high);

    return sum;
}

int main()
{

    return 0;
}