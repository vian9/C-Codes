// Link : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Time Complexity : O(3 * n)
// Approach-> Phle traverse kia count kia....phir k groups wise reverse kia aage uske null krke and jo bach gya rhne dia

#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;
#define ll long long int

// Given a head this function reverse the LL and returns the new head
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *nex = head->next;
    ListNode *rev = reverseList(head->next);
    nex->next = head;
    head->next = nullptr;
    return rev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }
    int count = 0;
    ListNode *temp = head;
    // total count of nodes chahiye hi chahiye
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    // Ab 1st se start kia
    int len = 1;
    ListNode *revHead = head;
    temp = head;
    // If temp ie head null nhi to phla k groups...ye issliye jruri taki hum revHead return kr ske
    if (temp != nullptr)
    {
        ListNode *start = temp;
        while (len < k && temp != nullptr)
        {
            len++;
            temp = temp->next;
        }
        ListNode *end = nullptr;
        // Null issliye ki bs k groups reverse hokr aye issliye usse end krna jruri h
        if (temp)
            end = temp->next;
        if (temp)
            temp->next = nullptr;
        // reverse krdia list ko
        revHead = reverseList(start);
        // Ab reversed list ke aage wla jo next thay usse connect krdo
        start->next = end;
        // Temp ko move krdia
        temp = start;
    }
    count = count - k;
    for (int i = 0; i < count / k; i++)
    {
        len = 1;
        // Last k connection uske aage reverse krna h
        ListNode *last = temp;
        ListNode *start = temp->next;
        temp = temp->next;
        while (len < k && temp != nullptr)
        {
            len++;
            temp = temp->next;
        }
        ListNode *end = nullptr;
        if (temp)
            end = temp->next;
        if (temp)
            temp->next = nullptr;
        ListNode *revHead2 = reverseList(start);
        last->next = revHead2;
        start->next = end;
        temp = start;
    }
    // Agar k groups m last wla bachrha to usse waise hi rhne do
    return revHead;
}

int main()
{

    return 0;
}