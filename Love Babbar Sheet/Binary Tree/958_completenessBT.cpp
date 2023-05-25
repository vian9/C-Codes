// Link : https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// Time Complexity : O(n)
// Approach-> Phle count krlo saara nodes and then dfs se usse index do and check kro
// BFS is fast nd easy to check null

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

// BFS...jaise hi last null aaya uske baad kuch bhi aaya to false

bool bfsSearch(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    queue<TreeNode *> pq;
    pq.push(root);
    bool nullLast = false;
    while (!pq.empty())
    {
        TreeNode *front = pq.front();
        pq.pop();
        // Null aagya true krdia
        if (front == nullptr)
        {
            nullLast = true;
        }
        else
        {
            // Ab null k baad kuch bhi aaye send false
            if (nullLast)
                return false;
            else
            {
                pq.push(front->left);
                pq.push(front->right);
            }
        }
    }
    return true;
}

bool isCompleteTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    return bfsSearch(root);
}

// DFS
int countNodes(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool dfsSearch(TreeNode *root, int index, int n)
{
    if (root == nullptr)
    {
        return true;
    }

    // Harr nodes ko index assign krdia aur agar usse index se exceed krrha to complete nhi h
    if (index >= n)
    {
        return false;
    }
    // Index 0 se start horha
    return dfsSearch(root->left, 2 * index + 1, n) && dfsSearch(root->right, 2 * index + 2, n);
}

bool isCompleteTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    return dfsSearch(root, 0, countNodes(root));
}

int main()
{

    return 0;
}