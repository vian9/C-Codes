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

// Optimised code - not using extra space
// Dono nodes m modify krrha and tail ko move krdia
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    int carry = 0;
    ListNode *tail = temp1;
    // temp1 and temp2 k nodes m update krrhe
    while (temp1 != nullptr && temp2 != nullptr)
    {
        int sum = temp1->val + temp2->val + carry;
        carry = 0;
        if (sum > 9)
        {
            sum = sum - 10;
            carry = 1;
        }
        temp1->val = sum;
        temp2->val = sum;
        tail = temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    bool flag = false;
    // ab flag se pta kr skte temp1 h ya temp2
    while (temp1 != nullptr)
    {
        int sum = temp1->val + carry;
        carry = 0;
        if (sum > 9)
        {
            sum = sum - 10;
            carry = 1;
        }
        temp1->val = sum;
        tail = temp1;
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        int sum = temp2->val + carry;
        carry = 0;
        if (sum > 9)
        {
            sum = sum - 10;
            carry = 1;
        }
        temp2->val = sum;
        tail = temp2;
        temp2 = temp2->next;
        flag = true;
    }
    if (carry == 1)
    {
        ListNode *newNode = new ListNode(1);
        tail->next = newNode;
        newNode->next = nullptr;
    }
    // ab usse m modified h daldo
    if (flag)
        return l2;
    else
        return l1;
}

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