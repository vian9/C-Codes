// Link : https://leetcode.com/problems/middle-of-the-linked-list/
// Time Complexity : O(n/2)
// Approach-> Slow nd fast 2 pointer maintain krlia and check for even nd odd ki fast kahan hoga
// jab slow mid pr hoga toh.....also 2nd mid element in even k case mein fast->next == NULL se checkrlo
// can't use fast->next->next == NULL bcoz odd k case mein ye NULL->next k karan error dega

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // can't use fast->next->next == NULL bcoz odd k case mein ye NULL->next k karan error dega
    if (fast->next == NULL)
    {
        return slow;
    }
    else
    {
        return slow->next;
    }
}

ListNode *middleNode(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // directly slow return krdo
    return slow;
}

int main()
{

    return 0;
}