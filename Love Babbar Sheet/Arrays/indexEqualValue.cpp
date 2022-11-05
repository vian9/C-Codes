// Link : https://www.codingninjas.com/codestudio/problems/value-equal-to-the-index-value_1115771?topList=love-babbar-dsa-sheet-problems
// Time Complexity : O(n)
// Approach-> Agar condition match to push and agar uska count zero to vector mein -1 push krdia and finally vector return.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> valueEqualToIndices(vector<int> &numArray, int n)
{
    vector<int> val;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (numArray[i] == i)
        {
            val.push_back(numArray[i]);
            count++;
        }
    }
    if (count == 0)
    {
        val.push_back(-1);
    }
    return val;
}

int main()
{

    return 0;
}