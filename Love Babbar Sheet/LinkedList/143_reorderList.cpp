// Link : https://leetcode.com/problems/reorder-list/
// Time Complexity : O(n)
// Approach-> Phle Slow nikal lia whi se reverse krke dono LL ko merge krdo one by one
// slow issliye kuuki wo even aur odd koi k liye bhi whi se merge horha

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseLL(ListNode *head)
{
    // Recursion se reverse LL krdia
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *smallLL = reverseLL(head->next);
    // pura LL except head reverse hogya....ab head jo h 2nd node k next mein connect krdo uske liye head->next->next
    head->next->next = head;
    head->next = nullptr;
    return smallLL;
}

void reorderList(ListNode *head)
{
    // Edge case
    if (head == nullptr)
        return;

    // slow and fast se mid nikalo and slow se add krenge
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Slow ka next ko reverse krna h
    ListNode *reverse = reverseLL(slow->next);
    // slow se phle k next mein null lagado
    slow->next = nullptr;
    ListNode *temp1 = head;
    // Ab dono LL ko merge krdo
    ListNode *temp2 = reverse;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        ListNode *next1 = temp1->next;
        ListNode *next2 = temp2->next;
        temp1->next = temp2;
        temp2->next = next1;
        temp1 = next1;
        temp2 = next2;
    }
}

int main()
{

    return 0;
}