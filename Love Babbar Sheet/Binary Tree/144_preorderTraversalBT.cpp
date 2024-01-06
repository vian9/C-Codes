// Link : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Time Complexity : O(n)
// Approach-> Root ko push phir left and right call

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

vector<int> v;
vector<int> preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};

    // phle root push phir left and right ko call
    v.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    return v;
}

// Queue can't be used bcoz wo level order hoga anadar depth m ni jaa skta
// Iterative dfs- using stack
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;

    if (root)
        st.push(root);

    while (!st.empty())
    {
        TreeNode *front = st.top();
        st.pop();

        // Since stack is LIFO so phle right phir left push kro
        if (front != nullptr)
        {
            ans.push_back(front->val);
            st.push(front->right);
            st.push(front->left);
        }
    }
    return ans;
}

int main()
{

    return 0;
}