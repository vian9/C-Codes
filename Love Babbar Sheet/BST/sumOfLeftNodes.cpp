// Link : https://leetcode.com/problems/sum-of-left-leaves/
// Time Complexity : O(n)
// Approach-> Just push the leaf node which is in left of root and no child.....otherwise call the left and right

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Using Level Order Queue
int sumOfLeftLeaves(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    queue<TreeNode *> pendingNodes;
    int sum = 0;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        // Isme left leaf node phle hi add krdia kuuki koi bool ya identifier nhi pass krrhe toh check ki left se aaya h
        //  Otherwise andar add krte to saare leaf nodes k sum aa jata
        if (front->left != nullptr && front->left->left == nullptr && front->left->right == nullptr)
        {
            sum += front->left->val;
        }
        if (front->left != nullptr)
        {
            pendingNodes.push(front->left);
        }
        if (front->right != nullptr)
        {
            pendingNodes.push(front->right);
        }
    }
    return sum;
}

// Using Recursion
int sumOfLeftLeaves(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return sumOfLeftChild(root, false);
}

int sumOfLeftChild(TreeNode *root, bool b)
{
    // Leaf node in left with no child
    if (b && root->left == nullptr && root->right == nullptr)
    {
        return root->val;
    }
    else
    {
        // Yeh Bool True and false yhi check krne k liye h ki left se aaya h...if true mtlb left se call h and aage add hoga
        int val1 = 0, val2 = 0;
        if (root->left)
        {
            val1 = sumOfLeftChild(root->left, true);
        }
        if (root->right)
        {
            val2 = sumOfLeftChild(root->right, false);
        }
        return val1 + val2;
    }
}

int main()
{

    return 0;
}