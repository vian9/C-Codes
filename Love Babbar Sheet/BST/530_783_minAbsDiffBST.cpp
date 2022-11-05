// Link : https://leetcode.com/problems/minimum-absolute-difference-in-bst/
//      : https:leetcode.com/problems/minimum-distance-between-bst-nodes/
// Time Complexity : O(n)
// Approach-> 3 possibility are there.....ya phir koi subtree mein hi mini mil jaye update with it
// or max of left - root or min of right - root se bhi mil skta h

// much easier way by using vector could be ki Inorder traversal krdo....aur consecutive ka abs diff lelo....Inorder
// traversal mein sorted order mein array aata

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

// <Mini , <min, max>> yhi h pair me....
pair<int, pair<int, int>> getMin(TreeNode *root)
{
    // Edge Case
    if (!root)
    {
        pair<int, pair<int, int>> p = {0, {0, 0}};
        return p;
    }
    // Base Case
    // Agar no child pr aaya h....toh mini mein infinite aur baaki sav mein min and max daal do
    if (!root->left && !root->right)
    {
        pair<int, pair<int, int>> p = {INT_MAX, {root->val, root->val}};
        return p;
    }

    int first = root->val;
    pair<int, pair<int, int>> ans = {INT_MAX, {INT_MAX, INT_MIN}};
    if (root->left)
    {
        pair<int, pair<int, int>> leftMin = {INT_MAX, {INT_MAX, INT_MIN}};
        // mini update krdo
        ans.first = min(abs(first - root->left->val), ans.first);
        leftMin = getMin(root->left);
        // min max update krdo aage kaam aayega
        ans.second.first = min(ans.second.first, min(root->left->val, leftMin.second.first));
        ans.second.second = max(ans.second.second, max(root->left->val, leftMin.second.second));
        // mini phir update krdo agar udhar se aaya mein min h to
        ans.first = min(abs(leftMin.second.second - first), min(ans.first, leftMin.first));
    }
    if (root->right)
    {
        pair<int, pair<int, int>> rightMin = {INT_MAX, {INT_MAX, INT_MIN}};
        ans.first = min(ans.first, abs(first - root->right->val));
        rightMin = getMin(root->right);
        ans.second.first = min(ans.second.first, min(root->right->val, rightMin.second.first));
        ans.second.second = max(ans.second.second, max(root->right->val, rightMin.second.second));
        ans.first = min(abs(rightMin.second.first - first), min(ans.first, rightMin.first));
    }
    return ans;
}

// Node val is positive
int getMinimumDifference(TreeNode *root, int mini = INT_MAX)
{
    if (!root)
    {
        return 0;
    }
    pair<int, pair<int, int>> ans = getMin(root);
    return ans.first;
}

int main()
{

    return 0;
}