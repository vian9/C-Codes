// VVI
// Link : https://leetcode.com/problems/linked-list-cycle-ii/
// Time Complexity : O(n or 2n) nd O(1) space
// Approach-> Slow ko ek se and fast ko 2 se move kro jbtk mil na jaye....uske baad if mein check krlo same h slow
// and fast to thik otherwise null return.....and finally slow ko head se and fast ko meeting point se chalao ek
// step se jbtk dono mil na jaye whi node will be ans
// Solution 2 : Can use hasing to store node address and if already present then usse node-> next is the begiining
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Floyd cycle algorithm
ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    slow = slow->next;
    fast = fast->next->next;

    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
        {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != fast)
    {
        return NULL;
    }

    // Resource : www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
    // To understand why this loop will return the exact correct beginning position
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// Solution 3 : Temp node bnaya and next of each node is made to point to this temp...this way next to point
// to temp is like a flag...now when we traverse the second time we traverse it will be pointing to temp just return that

ListNode *detectLoop(ListNode *head)
{

    // Create a temporary node
    ListNode *temp = new ListNode;
    while (head != NULL)
    {

        // This condition is for the case
        // when there is no loop
        if (head->next == NULL)
        {
            return NULL;
        }

        // Check if next is already
        // pointing to temp
        if (head->next == temp)
        {
            break;
        }

        // Store the pointer to the next node
        // in order to get to it in the next step
        ListNode *nex = head->next;

        // Make next point to temp
        head->next = temp;

        // Get to the next node in the list
        head = nex;
    }

    return head;
}

int main()
{

    return 0;
}