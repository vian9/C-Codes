// Link : https://leetcode.com/problems/diameter-of-binary-tree/
// Time Complexity : O(n)
// Approach-> Diamter will be max of either left or right diameter or leftHeigh+rightHeight
// So instead of calling 2 functions to get diamter and height ek hi function call mein krdiye

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

pair<int, int> diameterHeight(TreeNode *root)
{
    // Base Case
    if (!root)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> left = {0, 0};
    if (root->left)
        left = diameterHeight(root->left);
    pair<int, int> right = {0, 0};
    if (root->right)
        right = diameterHeight(root->right);

    // Height will be root + max
    int height = 1 + max(left.second, right.second);
    // Diameter 3 mein se jo max
    int diameter = max(left.first, max(right.first, left.second + right.second));

    pair<int, int> ans;
    ans.first = diameter;
    ans.second = height;
    return ans;
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    // Pair of diameter and height
    pair<int, int> ans = diameterHeight(root);
    return ans.first;
}

int main()
{

    return 0;
}