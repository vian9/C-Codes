// Link : https://leetcode.com/problems/delete-node-in-a-linked-list/
// Time Complexity : O(1)
// Approach-> Ek node create krdia jiska value jo Node delete krna h uska next->val k equal hai
// ab wo new Node k next mein jo delete krna tha uska next->next daal diye
// Indirectly maine jo delete krna tha wahan se sbko htadia and temp se link krdia.....

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node)
{
    ListNode *temp = node; // Temp purana tk connected hai
    if (temp != NULL)
    {
        // temp mein next k value daal diye....mtlb hume jo dlt krna h uska agla node bnadiye
        temp->val = temp->next->val;
        // ab jo dlt k agla k agla nodes h usse temp se connect krdia
        temp->next = temp->next->next;
    }
}

int main()
{

    return 0;
}