// Link : https://leetcode.com/problems/subtree-of-another-tree/
// Time Complexity : O(n)....worst case mein pura tree same tb bhi pura node check
// Approach-> Phle root se agar subroot match krgya to isSameTree check krlo otherwise root ka left and right k sth call krdo

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

bool isSameTree(TreeNode *p, TreeNode *q)
{
    // Agar dono nodes null to thik otherwise koi ek null to false
    // Base case
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    else if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
    {
        return false;
    }

    // root alag to false
    if (p->val != q->val)
        return false;
    // Call left and right and check
    bool check1 = isSameTree(p->left, q->left);
    bool check2 = isSameTree(p->right, q->right);
    if (!check1)
        return false;
    if (!check2)
        return false;
    return true;
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (!root || !subRoot)
    {
        return false;
    }
    if (root->val == subRoot->val)
        if (isSameTree(root, subRoot))
            return true;

    bool checkLeft = isSubtree(root->left, subRoot);
    bool checkRight = isSubtree(root->right, subRoot);
    if (checkLeft)
        return true;
    if (checkRight)
        return true;
    return false;
}

int main()
{

    return 0;
}