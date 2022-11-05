// Link : https://practice.geeksforgeeks.org/problems/reverse-a-stack/1
// Time Complexity : O(n) .... recursion
// Approach-> Global declared vector.....ab Base case jb empty to return otherwise usse stack ko vector mein
// push krenge and phir pop and finally return the vector

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> v;

vector<int> Reverse(stack<int> St)
{
    // Base case
    if (St.empty())
    {
        return v;
    }

    // Induction step
    int num = St.top();
    v.push_back(num);
    St.pop();
    Reverse(St);
    return v;
}

int main()
{

    return 0;
}