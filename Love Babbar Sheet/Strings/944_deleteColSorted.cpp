// Link : https://leetcode.com/problems/delete-columns-to-make-sorted/
// Time Complexity : O(n^2)
// Approach-> Harr row m jao and update ascii in vector and next row m check for greater otherwise delete col

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minDeletionSize(vector<string> &strs)
{
    // vector k harr rows m jao and usse size tk iterate kro
    // easy way out is array lelo jisme hum input krke rkhe honge ascii value
    vector<int> val;
    for (int i = 0; i < strs[0].size(); i++)
    {
        int a = (int)strs[0][i];
        val.push_back(a);
    }
    int count = 0;
    for (int i = 1; i < strs.size(); i++)
    {
        for (int j = 0; j < strs[0].length(); j++)
        {
            int b = (int)strs[i][j];
            // if col deleted toh dont consider
            if (val[j] == -1)
            {
                continue;
            }
            // agar wo col delete hogya h to htado by updating value -1
            else if (val[j] > b)
            {
                val[j] = -1;
                count++;
            }
            else
            // update the value
            {
                val[j] = b;
            }
        }
    }
    return count;
}

int main()
{

    return 0;
}