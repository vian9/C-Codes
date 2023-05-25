// Link : https://leetcode.com/problems/merge-two-sorted-lists/
// Time Complexity : O(n)
// Approach-> Phle head nd tail bnao and usse 1st smallest element se point krdo.....phir jbtk koi ek LL over na
// ho jaye tbtk iterate krke compare and tail->next mein dalte jao....ab over hone k baad jiska baaki h usko lagado
// Similar logic like Merge2Sorted Array in Merge Sort

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct ListNode
{
    *int val;
    *ListNode *next;
    *ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution 2-> 7ms.....koi new node nhi bnarhe bas purana LL ko arrange krrhe
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    // jab dono me se koi ek LL Null ho, agar dono me ek bhi element hai to wo bhi compare krke return kr dega
    ListNode *h1 = list1;
    ListNode *h2 = list2;
    ListNode *finalHead = NULL;
    ListNode *finalTail = NULL;
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    if (h1->val > h2->val)
    {
        finalHead = h2;
        finalTail = h2;
        // Update nhi krenge to h2 phir se finalHead phir se whi node ko compare krke add krega
        // but ye to ek obj h node with an specific address to 2 baar add kaise hoga to aage run nhi krega
        // indirectly mtlb yhi h isse hum aage jab phir se compare krte while loop m and finalTail m dalte to khud ko hi point krne bolte
        h2 = h2->next;
    }
    else
    {
        finalHead = h1;
        finalTail = h1;
        h1 = h1->next;
    }

    while (h1 != NULL && h2 != NULL)
    // dono condition satisfy krna chahiye-mtlb tb tk chlega jbtk koi ek LL exhaust na ho jaye
    {
        if (h1->val > h2->val)
        {
            finalTail->next = h2;
            finalTail = finalTail->next;
            h2 = h2->next;
        }
        else
        {
            finalTail->next = h1;
            finalTail = finalTail->next;
            h1 = h1->next;
        }
    }

    if (h1 != NULL)
    {
        // yhan while loop bhi laga kr kr skte thay but jrurt nhi tha wo bas time complexity badhata
        // since aage ka LL already connected hai to bas finalTail se head 1 ko jorr dia pura final LL aa jayega
        finalTail->next = h1;
    }

    if (h2 != NULL)
    {
        finalTail->next = h2;
    }

    return finalHead;
}

// Solution 1 -> 14ms.....new node bnakr daalrhe
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head1 = list1;
    ListNode *head2 = list2;
    ListNode *head3 = NULL;
    ListNode *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        ListNode *newNode = new ListNode();
        if (head3 == NULL)
        {
            if (head1->val > head2->val)
            {
                head3 = newNode;
                tail = newNode;
                head3->val = head2->val;
                head2 = head2->next;
            }
            else
            {
                head3 = newNode;
                tail = newNode;
                head3->val = head1->val;
                head1 = head1->next;
            }
        }
        else
        {
            if (head1->val > head2->val)
            {
                tail->next = newNode;
                tail = tail->next;
                tail->val = head2->val;
                head2 = head2->next;
            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
                tail->val = head1->val;
                head1 = head1->next;
            }
        }
    }
    while (head1 != NULL)
    {
        ListNode *newNode = new ListNode();
        if (head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
            head3->val = head1->val;
            head1 = head1->next;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
            tail->val = head1->val;
            head1 = head1->next;
        }
    }

    while (head2 != NULL)
    {
        ListNode *newNode = new ListNode();
        if (head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
            head3->val = head2->val;
            head2 = head2->next;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
            tail->val = head2->val;
            head2 = head2->next;
        }
    }

    return head3;
}

int main()
{

    return 0;
}