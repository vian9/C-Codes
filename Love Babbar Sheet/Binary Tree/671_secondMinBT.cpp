// Link : https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
// Time Complexity : O(n)
// Approach-> Ek pair lelia jisme min and 2nd min hoga.....to 1st mein 2nd min hoga
// Agar diff value h tbhi return krenge agar same value or no value par -1 return krdo
// Phle -1 jb h toh phle second ko update kro and keep min at 2nd taki hum compare kr ske woh value aaya to nhi h

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

void minSecinTree(TreeNode *root, pair<int, int> &mini)
{
    if (!root)
    {
        return;
    }

    if ((mini.first == -1 || mini.second == -1) && mini.second != root->val)
    {
        if (mini.second != -1)
        {
            mini.first = root->val;
            if (mini.first < mini.second)
            {
                swap(mini.first, mini.second);
            }
        }
        else
        {
            mini.second = root->val;
        }
    }
    else if (mini.first > root->val && mini.second != root->val)
    {
        mini.first = root->val;
        if (mini.first < mini.second)
        {
            swap(mini.first, mini.second);
        }
    }
    minSecinTree(root->left, mini);
    minSecinTree(root->right, mini);
    return;
}

int findSecondMinimumValue(TreeNode *root)
{
    if (!root)
    {
        return -1;
    }
    pair<int, int> mini = {-1, -1};
    minSecinTree(root, mini);

    if (mini.first == -1 || mini.second == -1)
    {
        return -1;
    }
    return max(mini.first, mini.second);
}

int main()
{

    return 0;
}