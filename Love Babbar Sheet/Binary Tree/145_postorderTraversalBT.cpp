// Link : https://leetcode.com/problems/binary-tree-postorder-traversal/
// Time Complexity : O(n)
// Approach-> Root ko push baad me phle left and right call

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

vector<int> v;
vector<int> postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};

    // baad mein root push phir left and right ko call
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    v.push_back(root->val);
    return v;
}

int main()
{

    return 0;
}