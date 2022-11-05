// Link : https://leetcode.com/problems/binary-tree-tilt/
// Time Complexity : O(n)
// Approach-> Pair mein return krdo ek Original value aur ek tilted aur har step pr original aur tilted k sum lete jao

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

pair<int, int> tiltSum(TreeNode *root)
{
    if (!root->left && !root->right)
    {
        // first mein value and second mein tilted value
        pair<int, int> p;
        p.first = root->val;
        root->val = 0;
        p.second = root->val;
        return p;
    }

    // Left check kro and sum lo...similarly check for right
    pair<int, int> leftSum;
    if (root->left)
        leftSum = tiltSum(root->left);
    pair<int, int> rightSum;
    if (root->right)
        rightSum = tiltSum(root->right);
    pair<int, int> ans;
    // Value saara k sum lelo taaki aage jakr uska difference nikal ske
    ans.first = root->val + leftSum.first + rightSum.first;
    // Ab tilted k liye root ka value update kro
    if (!root->left)
        root->val = abs(rightSum.first);
    else if (!root->right)
        root->val = abs(leftSum.first);
    else
        root->val = abs(leftSum.first - rightSum.first);
    // Ab saara tilted k sum lelo
    ans.second = root->val + leftSum.second + rightSum.second;
    return ans;
}

int findTilt(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    pair<int, int> ans = tiltSum(root);
    return ans.second;
}

int main()
{

    return 0;
}