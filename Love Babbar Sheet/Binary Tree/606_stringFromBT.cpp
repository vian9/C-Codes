// Link : https://leetcode.com/problems/construct-string-from-binary-tree/
// Time Complexity : O(n)
// Approach-> Bas Binary Tree mein ye dhyan rkho ki left ya right child na ho to kaise aur finally dono child na ho to kya krna h ye

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

string tree2str(TreeNode *root)
{
    if (!root)
    {
        string s;
        return s;
    }

    // Agar koi child nhi to root ko insert krke dedo
    if (!root->left && !root->right)
    {
        string tmp = (to_string(root->val));
        return tmp;
    }

    // Root ko phir Left ko insert kro
    string tmp = to_string(root->val) + "(";
    if (root->left)
    {
        string s1 = tree2str(root->left);
        tmp = tmp + s1;
    }
    // Agar left nhi h to bhi brackets dalna h
    tmp += +")";
    if (root->right)
    {
        tmp += "(";
        string s2 = tree2str(root->right);
        tmp = tmp + s2 + ")";
    }

    return tmp;
}

int main()
{

    return 0;
}