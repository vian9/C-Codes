// Link : https://leetcode.com/problems/binary-tree-postorder-traversal/
// Time Complexity : O(n)
// Approach-> Root ko push baad me phle left and right call

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

vector<int> v;
vector<int> postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};

    // baad mein root push phir left and right ko call
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    v.push_back(root->val);
    return v;
}

// Iterative - Using Stack DFS
vector<int> postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<int> ans;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        // Stack h to LIFO to left and then right and then root ka value dalo...to sequence mein aayega curr ka value and then right phir left
        if (curr != nullptr)
        {
            st.push(curr->left);
            st.push(curr->right);
            ans.push_back(curr->val);
        }
    }
    // reverse the order is postorder...as it had root val then right and left
    reverse(ans.begin(), ans.end());
    return ans;
}

// Iterative - Single DFS
vector<int> postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (curr != nullptr || !st.empty())
    {
        // If not null to right child ko move krte jao and push into stack
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            // Else right child pr aao
            TreeNode *temp = st.top()->right;
            if (temp == nullptr)
            {
                // If right child is now null to push it's parent ie top and pop it out
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                // Now the present parent is the right child of top then pop it out and print
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            else
            {
                // Right child exists to usse ab move
                curr = temp;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}