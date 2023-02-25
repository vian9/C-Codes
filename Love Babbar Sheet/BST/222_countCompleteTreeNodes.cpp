// Link : https://leetcode.com/problems/count-complete-tree-nodes/
// Time Complexity : O(n)
// Approach-> Agar left ka child h and right ka child h to return 1.....otherwise leftNodes and rightNodes ka sum lo
// and add krke + 1 return krdo

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

int countNodes(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }

    int leftNodes = 0;
    if (root->left)
        leftNodes = countNodes(root->left);
    int rightNodes = 0;
    if (root->right)
        rightNodes = countNodes(root->right);
    return leftNodes + rightNodes + 1;
}

int main()
{

    return 0;
}