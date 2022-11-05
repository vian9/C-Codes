// Link : https://leetcode.com/problems/binary-tree-inorder-traversal/
// Time Complexity : O(n)
// Approach-> Recursive approach phle left phir root phir right ko call

#include <bits/stdc++.h>
#include <TreeNode.h>
using namespace std;
#define ll long long int

// Globally vector lelia
vector<int> inorder;
vector<int> inorderTraversal(TreeNode *root)
{
    // If root is null to return
    if (root == nullptr)
        return inorder;

    // phle left ko call phir root phir right
    inorderTraversal(root->left);
    inorder.push_back(root->val);
    inorderTraversal(root->right);
    return inorder;
}

int main()
{

    return 0;
}