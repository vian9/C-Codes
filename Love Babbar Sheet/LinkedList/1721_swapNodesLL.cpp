// Link : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Time Complexity : O(n)
// Approach-> Phle k ko save kia and then last k ko and then swap values

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ListNode *swapNodes(ListNode *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }
    // Phle first m phla k ko save kia
    ListNode *temp = head;
    ListNode *first = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            first = temp;
        }
        temp = temp->next;
    }
    count -= k;
    // Ab last m last wla se k ko save krenge
    ListNode *last = head;
    temp = head;
    while (temp != nullptr && count > 0)
    {
        count--;
        temp = temp->next;
    }
    last = temp;
    // Now just swap the values
    int firstt = first->val;
    first->val = last->val;
    last->val = firstt;
    return head;
}

int main()
{

    return 0;
}