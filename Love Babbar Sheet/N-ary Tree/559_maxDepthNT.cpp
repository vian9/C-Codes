// Link : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Time Complexity : O(n)
// Approach-> Children ko maxDepth k liye call kro aur max update kro and finally 1+ krke return kro

#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
#define ll long long int

int maxDepth(Node *root)
{
    // Yeh Edge case h not base case as yeh tbhi hoga jab root mein kuch nhi dega
    if (root == NULL)
        return 0;

    int maxxDepth = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int depth = maxDepth(root->children[i]);
        maxxDepth = max(depth, maxxDepth);
    }
    // Last level pr koi children nhi tb 1 + 0 return ho jayega
    return 1 + maxxDepth;
}

int main()
{

    return 0;
}