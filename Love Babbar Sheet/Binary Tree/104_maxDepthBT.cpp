// Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Time Complexity : O(n)
// Approach-> Left and Right ka depth nikalo...aur +1 for root krdo

#include <bits/stdc++.h>
#include <TreeNode.h>
using namespace std;
#define ll long long int

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

int main()
{

    return 0;
}