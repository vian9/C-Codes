// Link : https://leetcode.com/problems/cousins-in-binary-tree/
// Time Complexity : O(n)....Stack Space(2N)
// Approach-> Level and parents dedia aur agar value match to pair mein parents aur depth return krdega...just compare the value of parents and depth

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

// Parents and depth in pair
pair<int, int> depthPar(TreeNode *root, int x, int k, int parents)
{
    if (!root)
    {
        pair<int, int> v = {-1, -1};
        return v;
    }
    // Agar root k barabar to whi depth and purana parents
    if (root->val == x)
    {
        pair<int, int> ans;
        ans.first = parents;
        ans.second = k;
        return ans;
    }
    // Otherwise parents becomes root and check left and right with 2 different pairs aur value aaye to return
    // 2 different pairs issliye otherwise value conflict ho jayega left and right ko same pair denge to
    parents = root->val;
    if (root->left)
    {
        pair<int, int> ans;
        ans = depthPar(root->left, x, k + 1, parents);
        if (ans.first != -1 && ans.second != -1)
            return ans;
    }
    if (root->right)
    {
        pair<int, int> ans;
        ans = depthPar(root->right, x, k + 1, parents);
        if (ans.first != -1 && ans.second != -1)
            return ans;
    }
    return {-1, -1};
}

bool isCousins(TreeNode *root, int x, int y)
{
    if (!root)
    {
        return true;
    }
    pair<int, int> firstNode = depthPar(root, x, 0, 0);
    pair<int, int> secondNode = depthPar(root, y, 0, 0);
    if (firstNode.first == -1 && firstNode.second == -1)
    {
        return false;
    }
    if (secondNode.first == -1 && secondNode.second == -1)
    {
        return false;
    }
    if (firstNode.first == secondNode.first)
        return false;
    if (firstNode.second != secondNode.second)
        return false;
    return true;
}

int main()
{

    return 0;
}