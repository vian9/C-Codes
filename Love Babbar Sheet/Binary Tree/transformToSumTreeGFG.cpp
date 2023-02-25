// Link : https://practice.geeksforgeeks.org/problems/d7e0ce338b11f0be36877d9c35cc8dfad6636957/1
// Time Complexity : O(n)
// Approach-> Left and right ko update and return dfs.....same as Binary tree logic

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int sum(Node *node)
{
    int val = 0;
    // Agar left and right dono null to update 0 and return 0
    if (!node->left && !node->right)
    {
        int nodeval = node->data;
        node->data = 0;
        return 0;
    }
    // val lelo left ka and uske child ka add krke
    if (node->left)
    {
        val += (node->left->data) + sum(node->left);
    }
    if (node->right)
    {
        val += (node->right->data) + sum(node->right);
    }
    // update val
    node->data = val;
    return val;
}

// Agar node null nhi to transform the rest and finally root ko update
void toSumTree(Node *node)
{
    if (!node)
    {
        return;
    }

    int val = sum(node);
    node->data = val;
}

int main()
{

    return 0;
}