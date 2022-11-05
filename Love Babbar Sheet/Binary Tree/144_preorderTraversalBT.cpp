// Link : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Time Complexity : O(n)
// Approach-> Root ko push phir left and right call

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

vector<int> v;
vector<int> preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};

    // phle root push phir left and right ko call
    v.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    return v;
}

int main()
{

    return 0;
}