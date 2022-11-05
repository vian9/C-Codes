// Link : https://leetcode.com/problems/leaf-similar-trees/
// Time Complexity : O(n)
// Approach-> Phle dono ka saara leaf nodes k sequence vector mein lelia aur phir compare krdia and return bool

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

void leafChild(TreeNode *root, vector<int> &rootNode1)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        rootNode1.push_back(root->val);
    }
    leafChild(root->left, rootNode1);
    leafChild(root->right, rootNode1);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return true;

    if ((!root1 && root2) || (root1 && !root2))
    {
        return false;
    }

    vector<int> rootNode1;
    vector<int> rootNode2;
    leafChild(root1, rootNode1);
    leafChild(root2, rootNode2);
    int n = rootNode1.size();
    int m = rootNode2.size();
    if (n != m)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (rootNode1[i] != rootNode2[i])
            return false;
    }

    return true;
}

int main()
{

    return 0;
}