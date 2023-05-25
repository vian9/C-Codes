// Link : https://leetcode.com/problems/reverse-linked-list/
// Time Complexity : O(n)
// Approach-> Recursive approad toh mann lia ki baaki reverse hokr aagya hai bas head ko lagana hai
// So head->next mein toh 2nd node k address hai and 2nd node k next mein head lagana hai which is
// head->next->next....jo O(1) mein hogya no need of traversal each time so reduced time from O(n^2).

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

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *smallPair = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallPair;
}

int main()
{

    return 0;
}