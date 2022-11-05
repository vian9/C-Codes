// Link : https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Time Complexity : O(n)
// Approach-> Root ko push kia aur phir saare ke children pr call krdia

#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
#define ll long long int

vector<int> v;
vector<int> preorder(Node *root)
{
    if (root == NULL)
    {
        return {};
    }

    v.push_back(root->val);
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
    return v;
}

int main()
{

    return 0;
}