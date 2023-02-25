// Link : https://practice.geeksforgeeks.org/problems/d7e0ce338b11f0be36877d9c35cc8dfad6636957/1
// Time Complexity : O(n)
// Approach-> Agar leaf node toh 0 update kro and return 0....and uske upar k nodes m sum + call nodes.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int sum(Node *node)
{
    int val = 0;
    if (!node->left && !node->right)
    {
        int nodeval = node->data;
        node->data = 0;
        return 0;
    }
    if (node->left)
    {
        val += (node->left->data) + sum(node->left);
    }
    if (node->right)
    {
        val += (node->right->data) + sum(node->right);
    }
    node->data = val;
    return val;
}
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