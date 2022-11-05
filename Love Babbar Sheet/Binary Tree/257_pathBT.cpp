// Link : https://leetcode.com/problems/binary-tree-paths/
// Time Complexity : O(n)
// Approach-> Phle string nd vector bhejdo.....jaise hi end mein aayega last node ko concatenate krke vector mein insert krdo

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

void binaryTree(TreeNode *root, vector<string> &ans, string temp)
{
    if (!root->left && !root->right)
    {
        // to_string function typecaste anyone to string
        ans.push_back(temp + to_string(root->val));
    }

    // if left and right are not null to call
    if (root->left)
        // Ab root->val dalkr bhejo aur aage wo lagalega
        binaryTree(root->left, ans, temp + to_string(root->val) + "->");
    if (root->right)
        binaryTree(root->right, ans, temp + to_string(root->val) + "->");
}

vector<string> binaryTreePaths(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    vector<string> ans;
    string temp;
    binaryTree(root, ans, temp);
    return ans;
}

int main()
{

    return 0;
}