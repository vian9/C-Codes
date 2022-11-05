// Link : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// Time Complexity : O(n)
// Approach-> Root level k node hmesa add hoga aur usse bada hona chahiye
// to left and right maxi lelia aur wo bhejte gye agar usse bada h mtlb uske aane wala harr path se bada h

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

int goodNodes(TreeNode *root, int k = 0, int maxi = -1)
{
    if (!root)
    {
        return 0;
    }

    int sum = 0;
    int maxiLeft, maxiRight;
    if (k == 0)
    {
        sum += 1;
        maxi = root->val;
        maxiLeft = maxi;
        maxiRight = maxi;
    }
    // missing saare ancestorse se bade hone chhaiye toh ek maxiLeft and maxiRight lelia jo left and right k max maintain krke bhejega
    if (root->left)
    {
        if (root->left->val >= root->val && root->left->val >= maxi)
            sum += 1;
        if (maxi < root->left->val)
            maxiLeft = root->left->val;
        sum += goodNodes(root->left, k + 1, maxiLeft);
    }

    if (root->right)
    {
        if (root->right->val >= root->val && root->right->val >= maxi)
            sum += 1;
        if (maxi < root->right->val)
            maxiRight = root->right->val;
        sum += goodNodes(root->right, k + 1, maxiRight);
    }
    return sum;
}

int main()
{

    return 0;
}