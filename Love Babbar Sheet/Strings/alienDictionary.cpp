// Link : https://leetcode.com/problems/verifying-an-alien-dictionary/
// Time Complexity : O(n^2)
// Approach-> Phle saara order and index map mein daal dia....ab bas aage wala word mein traverse kro and agar j next
// word se bada to false or agar char match nhi to map mein check krlo agar order nhi rha toh false

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isAlienSorted(vector<string> &words, string order)
{
    // Dictionary check krna h
    unordered_map<char, char> check;
    for (int i = 0; i < order.size(); i++)
    {
        check.insert({order[i], i});
    }

    for (int i = 0; i < words.size() - 1; i++)
    {
        int m = words[i].length();
        int n = words[i + 1].length();
        for (int j = 0; j < m; j++)
        {
            if (j >= n)
            {
                return false;
            }

            if (words[i][j] != words[i + 1][j])
            {
                if (check[words[i][j]] > check[words[i + 1][j]])
                {
                    return false;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return true;
}

int main()
{

    return 0;
}