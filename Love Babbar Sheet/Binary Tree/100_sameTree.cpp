// Link : https://leetcode.com/problems/same-tree/
// Time Complexity : O(n)
// Approach-> Phle null check krlo usse phir root check krlo aur left and right ko call krlo

#include <bits/stdc++.h>
#include <TreeNode.h>
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

int main()
{

    return 0;
}