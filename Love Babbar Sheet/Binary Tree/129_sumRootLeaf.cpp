// Link : https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Time Complexity : O()
// Approach-> Jha jha end aayega wha sum pushkrdo....harr step m 10 se multiply krke val add krte jao and finally sum lelo

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
#define ll long long int

vector<int> sum;
void sumVal(TreeNode *root, int val)
{
    if (root == nullptr)
        return;

    // value update krdia
    int currVal = root->val;
    val = val * 10;
    val += currVal;
    // Agar leaf node h to value lelo
    if (!root->left && !root->right)
    {
        sum.push_back(val);
        return;
    }
    if (root->left)
        sumVal(root->left, val);
    if (root->right)
        sumVal(root->right, val);
}

int sumNumbers(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int totalSum = 0;
    for (int i = 0; i < sum.size(); i++)
    {
        totalSum += sum[i];
    }
    return totalSum;
}

int main()
{

    return 0;
}