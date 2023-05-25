// Link : https://leetcode.com/problems/search-a-2d-matrix/
// Time Complexity : O(m+n)
// Approach-> Ek row rkhlo nad col rkhlo .....ab row and col ko move kro

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int low = 0;
    int high = matrix[0].size() - 1;
    while (low < matrix.size() && high >= 0)
    {
        if (matrix[low][high] == target)
        {
            return true;
        }
        // val jda h usse col ko ghatao
        else if (matrix[low][high] >= target)
        {
            high = high - 1;
        }
        // kaam h to row ko badhao
        else
        {
            low = low + 1;
        }
    }
    return false;
}

int main()
{

    return 0;
}