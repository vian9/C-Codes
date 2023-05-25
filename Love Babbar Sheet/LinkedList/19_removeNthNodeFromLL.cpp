// Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Time Complexity : O(n)
// Approach-> Phle count krdia total and phir start se pta chal gya kitnaa age jana h usse ek phle jao and wahan se connect krdo

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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int count = 0;
    ListNode *temp = head;
    ListNode *tail = head;
    // Tail ko end pr le aaye and count nikal liye
    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    // Ab start se kitna aage jana h yeh num se pata chal jayega
    int num = count - n;
    if (num != 0)
    {
        // Jbtk woh node se ek phle na aaye tbtk traverse kro
        while (num != 1)
        {
            tail = tail->next;
            num--;
        }
        // Ab usse tail k aage agla node k alawa sav aage wla connect krdia
        if (tail != NULL)
        {
            ListNode *a = tail->next->next;
            tail->next = a;
        }
    }
    // agar num = 0 hai mtlb head ko htana h
    if (num == 0)
    {
        ListNode *a = head->next;
        head = a;
    }
    return head;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == nullptr)
        return head;
    int count = 0;
    ListNode *slow = head;
    while (slow != nullptr)
    {
        count++;
        slow = slow->next;
    }
    cout << count;
    count = count - n;
    if (count == 0)
    {
        if (head->next != nullptr)
        {
            return head->next;
        }
        else
        {
            return nullptr;
        }
    }
    // Jbtk 1 pr na pahuche
    slow = head;
    while (count > 1)
    {
        slow = slow->next;
        count--;
    }
    slow->next = slow->next->next;
    return head;
}

int main()
{

    return 0;
}