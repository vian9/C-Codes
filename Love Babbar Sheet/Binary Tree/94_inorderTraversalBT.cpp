// Link : https://leetcode.com/problems/binary-tree-inorder-traversal/
// Time Complexity : O(n)....SC:O(1)
// Approach-> Recursive approach phle left phir root phir right ko call

#include <bits/stdc++.h>
#include <TreeNode.h>
using namespace std;
#define ll long long int

// Best Approach - Morris traversal
//  1 - 2 3 4 5 - 6 null
vector<int> inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};

    vector<int> inorder;
    TreeNode *curr = root;

    while (curr != nullptr)
    {
        // Two cases....if left is null toh curr ka value dalo and right mein move kro
        if (curr->left == nullptr)
        {
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            // Otherwise root ka left se ab uska right mein jao end tk and see if thread is there or not
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            // Sbse end 6 pr thread ni h toh thread lgao curr se connect krke right mein and curr ko left mein call krdo
            if (prev->right == nullptr)
            {
                prev->right = curr;
                curr = curr->left;
            }
            // Agar thread h toh htao usse...value push and then right mein jao
            else
            {
                prev->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

// Globally vector lelia
vector<int> inorder;
vector<int> inorderTraversal(TreeNode *root)
{
    // If root is null to return
    if (root == nullptr)
        return inorder;

    // phle left ko call phir root phir right
    inorderTraversal(root->left);
    inorder.push_back(root->val);
    inorderTraversal(root->right);
    return inorder;
}

// Iterative - using Stack DFS
vector<int> inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};

    vector<int> ans;
    stack<TreeNode *> st;
    // Curr ek pointer lelo
    TreeNode *curr = root;
    while (curr != nullptr || !st.empty())
    {
        // Curr ko left ghumte jao jbtk pura end na aaye and stack m push kro
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        // Ab top pr jo sbse left h whi aayega ya agar left ni tb root aayega
        curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        // Sbse end wla ka right
        curr = curr->right;
    }
    return ans;
}

int main()
{

    return 0;
}