// Link : https://leetcode.com/problems/add-two-numbers/
// Time Complexity : O(n)
// Approach-> First add the numbers and take a carry if sum>9....and usko insertkrdo.....ab jaise hi koi ek LL over
// to phir jo baaki h carry k sth add kro.....last mein check if carry exists toh ek last node mein wo insert krdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    ListNode *head3 = NULL;
    ListNode *tail = NULL;
    int num = 0;
    int carry = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        int num1 = temp1->val;
        int num2 = temp2->val;
        num += num1 + num2;
        if (num > 9)
        {
            carry = num - 10;
            num = 1;
        }
        else
        {
            carry = num;
            num = 0;
        }
        ListNode *newNode = new ListNode(carry);
        if (head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        int num1 = temp1->val;
        num += num1;
        if (num > 9)
        {
            carry = num - 10;
            num = 1;
        }
        else
        {
            carry = num;
            num = 0;
        }
        ListNode *newNode = new ListNode(carry);
        if (head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        int num1 = temp2->val;
        num += num1;
        if (num > 9)
        {
            carry = num - 10;
            num = 1;
        }
        else
        {
            carry = num;
            num = 0;
        }
        ListNode *newNode = new ListNode(carry);
        if (head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        temp2 = temp2->next;
    }
    if (num != 0)
    {
        ListNode *newNode = new ListNode(num);
        if (head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head3;
}

int main()
{

    return 0;
}