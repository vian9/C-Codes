// Link : https://leetcode.com/problems/symmetric-tree/
// Time Complexity : O(n)
// Approach-> To check left and right of root ko same tree pr call krdia
// AB isme kuuki symmetric check krna h to left ko right k sth call krenge usse root k child mein
// kuuki left child ka leftmost node right child ka rightmost node k jaisa same hona chahiye

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// to check if two BT are same
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
    // Call left and right and check....isme kuuki symmetric check krna h to left ko right k sth call krenge
    bool check1 = isSameTree(p->left, q->right);
    bool check2 = isSameTree(p->right, q->left);
    if (!check1)
        return false;
    if (!check2)
        return false;
    return true;
}

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    // Left and right ko same check k liye bhej dia
    return isSameTree(root->left, root->right);
}

int main()
{

    return 0;
}