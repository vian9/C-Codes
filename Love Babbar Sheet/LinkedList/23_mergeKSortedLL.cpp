// Link : https://leetcode.com/problems/merge-k-sorted-lists/
// Time Complexity : O(nodes^2).....with calling merge two LL ....if using Priority Queue it will be O(nodes log nodes)
// Approach-> Easy and fast approach......Just priority queue mein daaldo wo min top pr krdega and phir usse
// new LL bnado aur connect krte jao

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

// Comparator function
class compare
{
public:
    bool operator()(ListNode *L1, ListNode *L2)
    {
        return (L1->val > L2->val);
    }
};

// Easy and Fast Solution O(nodes log nodes)....
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int n = lists.size();
    // Priority queue initialise mein datatype....aur usse datatype is a list or array to wo aur compare class.....
    // by default min heap....for max heap just write greater in compare
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;

    for (int i = 0; i < n; i++)
    {
        ListNode *temp = lists[i];
        // If temp not null toh push
        if (temp)
            pq.push(temp);
    }
    // head ko initialise krna hoga kuuki aage head->next laga rhe h to null nhi rkh skte
    ListNode *head = new ListNode(0);
    ListNode *tail = head;

    while (pq.size() > 0)
    {
        ListNode *temp = pq.top();
        pq.pop();

        tail->next = temp;
        tail = temp;

        if (temp->next)
            pq.push(temp->next);
    }
    return head->next;
}

// Solution......koi new node nhi bnarhe bas purana LL ko arrange krrhe
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

// Called the function 2 Merge LL wo saara kaam krdia
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *head = nullptr;
    for (int i = 0; i < lists.size(); i++)
    {
        head = mergeTwoLists(head, lists[i]);
    }

    return head;
}

int main()
{

    return 0;
}