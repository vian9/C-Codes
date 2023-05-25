// Link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Time Complexity : O(n)
// Approach-> Root is last of postorder....ab root k index nikalo and subtree build krne k liye dedo

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

TreeNode *buildRemTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int preStart, int preEnd)
{
    if (inStart > inEnd || preStart > preEnd)
    {
        return nullptr;
    }
    // Last element in postorder is root
    TreeNode *root = new TreeNode(postorder[preEnd]);
    int ind = -1;
    // Ab iska index find krlo...hash map bhi use kr skte thay for O(1) mein index find krne k liye
    for (int i = 0; i <= inEnd; i++)
    {
        if (inorder[i] == root->val)
        {
            ind = i;
            break;
        }
    }

    // Ab left and right k size
    int leftSize = ind - inStart;
    int rightSize = inEnd - ind;
    // Dono tree bnakr connect krdo
    // Left k liye inorder 0 to ind - 1 and preorder prestart se jitna uska size h usme -1 as 0 se start h
    root->left = buildRemTree(inorder, inStart, ind - 1, postorder, preStart, preStart + leftSize - 1);
    // Inorder to ind+1 to end tk but preorder mein preEnd se size minus krke start pos and end will be PreEnd-1 as end pr root h
    root->right = buildRemTree(inorder, ind + 1, inEnd, postorder, preEnd - rightSize, preEnd - 1);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() <= 1)
    {
        if (inorder.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(inorder[0]);
        return root;
    }

    return buildRemTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}
int main()
{

    return 0;
}