// Link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Time Complexity : O(n)
// Approach-> Mid ko root bnadia.....left and right ko call krke wo bnakr dediye and just connect with root

#include <bits/stdc++.h>
#include <TreeNode.h>
using namespace std;
#define ll long long int

TreeNode *sortToBST(vector<int> &nums, int low, int high)
{
    // Base Case
    if (low > high)
        return nullptr;
    int mid = low + (high - low) / 2;
    int rootData = nums[mid];
    TreeNode *root = new TreeNode(rootData);
    TreeNode *leftChild = sortToBST(nums, low, mid - 1);
    TreeNode *rightChild = sortToBST(nums, mid + 1, high);
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    // Edge Case
    if (n < 1)
    {
        return nullptr;
    }
    TreeNode *root = sortToBST(nums, 0, nums.size() - 1);
    return root;
}

int main()
{

    return 0;
}