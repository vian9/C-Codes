// Link : https://leetcode.com/problems/balanced-binary-tree/
// Time Complexity : O(n)
// Approach-> Dono height aur balance ek hi recursive call se krdia

#include <bits/stdc++.h>
#include <TreeNode.h>
using namespace std;
#define ll long long int

// Yeh function height aur balance dono check krke derhe - O(n)
pair<bool, int> heightBalance(TreeNode *root)
{
    if (root == nullptr)
        return {true, 0};

    // Left and Right dono pr call
    pair<bool, int> leftHeightBalance = heightBalance(root->left);
    pair<bool, int> rightHeightBalance = heightBalance(root->right);
    pair<bool, int> p;
    p.first = true;
    // If height > 1 toh false daal dia
    if (abs(leftHeightBalance.second - rightHeightBalance.second) > 1)
        p.first = false;
    // Height bhi update krdia new wala k root milakr
    p.second = 1 + max(leftHeightBalance.second, rightHeightBalance.second);
    // Agar ek bhi false aaye left ya right se to false
    if (!leftHeightBalance.first || !rightHeightBalance.first)
        p.first = false;
    return p;
}

bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;
    pair<bool, int> p = heightBalance(root);
    return p.first;
}

// Height k liye function
int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Checking for balanced
bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;

    // Phle height k liye call
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    // Phir Left and Right to check balanced
    bool leftCheck = isBalanced(root->left);
    bool rightCheck = isBalanced(root->right);

    if (!leftCheck || !rightCheck)
        return false;
    return true;
}

int main()
{

    return 0;
}