// Link : https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Time Complexity : O(n)
// Approach-> First call the child and then push the root.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> v;
vector<int> postorder(Node *root)
{
    if (root == NULL)
    {
        return {};
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    v.push_back(root->val);
    return v;
}

int main()
{

    return 0;
}