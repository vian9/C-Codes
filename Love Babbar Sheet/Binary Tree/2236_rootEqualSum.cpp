// Link : https://leetcode.com/problems/root-equals-sum-of-children/
// Time Complexity : O(n)
// Approach-> Phle left se saare k sum lelo aur phir right se.....ab uska sum root k barabar hua to true

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

int sumOfChild(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    if (!root->left && !root->left)
    {
        return root->val;
    }
    int sum = 0;
    // Left child ka sum
    if (root->left)
    {
        sum += sumOfChild(root->left);
    }
    // right child ka sum
    if (root->right)
    {
        sum += sumOfChild(root->right);
    }
    // return sum of all child
    return sum;
}

bool checkTree(TreeNode *root)
{
    if (!root)
    {
        return true;
    }

    if (sumOfChild(root) == root->val)
    {
        return true;
    }
    return false;
}

int main()
{

    return 0;
}