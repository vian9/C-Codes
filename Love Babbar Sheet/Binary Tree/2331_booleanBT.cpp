// Link : https://leetcode.com/problems/evaluate-boolean-binary-tree/
// Time Complexity : O(n)
// Approach-> Agar leaf node h to based on 0 or 1 return directly.....otherwise in case of 2 child see rootVal and perform operation

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

bool evaluateTree(TreeNode *root)
{
    // Base case
    if (!root)
    {
        return true;
    }
    if (!root->left && !root->right)
    {
        if (root->val)
            return true;
        return false;
    }
    int rootVal = root->val;
    // Since every node has 0 or 2 children to koi dikkat nhi ...0 child k upar dekhlia ab 2 child ka
    bool leftCheck;
    if (root->left)
    {
        leftCheck = evaluateTree(root->left);
    }
    bool rightCheck;
    if (root->right)
    {
        rightCheck = evaluateTree(root->right);
    }
    if (rootVal == 2)
    {
        if (leftCheck || rightCheck)
            return true;
    }
    if (rootVal == 3)
    {
        return (leftCheck & rightCheck);
    }
    return false;
}

int main()
{

    return 0;
}