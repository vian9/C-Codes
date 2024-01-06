// Link : https://leetcode.com/problems/path-sum/
// Time Complexity : O(n)
// Approach-> Phle root agar null to return
// Ab root ka koi child nhi aur targetSum has val left equal to root to return true
// Ab left and right ko call krdo

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

bool isPathPos(TreeNode *root, int targetSum)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        // Important h isse step pr jab koi child nhi aur sum is left equal to root val
        if (targetSum == root->val)
            return true;
        return false;
    }

    return (isPathPos(root->left, targetSum - root->val) || isPathPos(root->right, targetSum - root->val));
}

// k.shailaja56030710@gmail.com

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;
    return isPathPos(root, targetSum);
}
int main()
{

    return 0;
}