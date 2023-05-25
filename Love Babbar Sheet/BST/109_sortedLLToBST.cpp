// Link : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
#include "TreeNode.h"
#include "ListNode.h"
using namespace std;
#define ll long long int

TreeNode *constructBST(int low, int high, vector<int> &nodes)
{
    // Ab Tree bnane k liye array to dia h...either array mein daaldo and pass krdo
    if (low > high)
    {
        return nullptr;
    }
    // Mid nikal lia aur usse root bnana lia
    int mid = (high - low) / 2 + low;
    TreeNode *root = new TreeNode();
    root->val = nodes[mid];
    // PMI se connect krdia jo lakr dia
    root->left = constructBST(low, mid - 1, nodes);
    root->right = constructBST(mid + 1, high, nodes);
    return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    vector<int> nodes;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        nodes.push_back(temp->val);
        temp = temp->next;
    }
    return constructBST(0, nodes.size() - 1, nodes);
}

int main()
{

    return 0;
}