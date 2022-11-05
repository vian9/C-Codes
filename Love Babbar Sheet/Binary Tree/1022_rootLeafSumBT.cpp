// Link : https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Time Complexity : O(n)
// Approach-> Phle root ko prev mein daalo aur prev*2 + rootVal se update krte jao....agar child h to wo leftPrev and rightPrev
// mein dalkr bhejdo prev ko kuuki haar path k calculate krna h decimal value issliye 2 leftPrev and rightPrev dia h
// Agar child h toh return leftPrev+rightPrev as it will contain prev value updated with the child and all possible values

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

// Prev binary value ko 2 se multiply kro and new binary value ko 2^0 i.e. 1 se multiply krke add and finally return
int sumRootToLeaf(TreeNode *root, int prev = 0)
{
    if (!root)
    {
        return 0;
    }
    // Phle prev update krdia
    prev = (prev)*2 + 1 * root->val;
    // no child to return prev
    if (!root->left && !root->right)
    {
        return prev;
    }
    int leftPrev = 0;
    int rightPrev = 0;
    // Agar child h to leftPrev and rightPrev mein prev dalkr bhejdo aur finally wo possible value calculate krke dedega
    if (root->left)
    {
        leftPrev = prev;
        leftPrev = sumRootToLeaf(root->left, leftPrev);
    }
    if (root->right)
    {
        rightPrev = prev;
        rightPrev = sumRootToLeaf(root->right, rightPrev);
    }
    // dono k sum return kuuki left and right dono se possible harr barr new bnega
    return leftPrev + rightPrev;
}

int main()
{

    return 0;
}