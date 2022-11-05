// Link : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Time Complexity : O(n)
// Approach-> Took a vector to store the values from the Linked List.
// Then just traverse the Linked List and push back value in vector.
// Finally used a loop to get the integer value.

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

int getDecimalValue(ListNode *head)
{
    vector<int> val;
    ListNode *temp = head;
    while (temp != NULL)
    {
        int num = temp->val;
        val.push_back(num);
        temp = temp->next;
    }
    int ans = 0;
    int powr = 1;
    for (int i = val.size() - 1; i >= 0; i--)
    {
        ans += (powr * val[i]);
        powr *= 2;
    }
    return ans;
}

int main()
{

    return 0;
}