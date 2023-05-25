// Link : https://leetcode.com/problems/linked-list-random-node/
// Time Complexity : O(n)
// Approach-> Hume solution mein LL ko list/vector mein return krna h aur getRandom mein ek random node k value return krna h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

class Solution
{
    // Vector for pushing nodes and n for LL size
    vector<int> ptr;
    int n;

public:
    Solution(ListNode *head)
    {
        // Saara nodes k value vector mein daalo and LL k size sochlo wo solution bnayega
        ListNode *temp = head;
        while (temp)
        {
            ptr.push_back(temp->val);
            temp = temp->next;
        }
        // Global variable already initialised h
        n = ptr.size();
    }

    int getRandom()
    {
        // Ab random node select kro jo 0 to n-1 tk dega
        int nodeSelect = rand() % n;
        return ptr[nodeSelect];
    }
};
int main()
{

    return 0;
}