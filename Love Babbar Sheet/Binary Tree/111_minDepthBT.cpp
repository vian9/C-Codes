// Link : https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Time Complexity : O(n)
// Approach-> Left and Right dono mein call krdiye aur just min depth return krdo

#include <bits/stdc++.h>
#include <TreeNode.h>
using namespace std;
#define ll long long int

int minDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    // Agar left mein 1st time hi kuch nhi to usko consider nhi krna h aur continous ho jo whi
    // Na ki left mein null h level 2 pr aur right mein chalrha to 2 + 1 return krdia waise nhi
    // Jahan tk connected chalrha wo check krna h
    if (leftDepth == 0)
        return 1 + rightDepth;
    if (rightDepth == 0)
        return 1 + leftDepth;
    return 1 + min(leftDepth, rightDepth);
}

int main()
{

    return 0;
}