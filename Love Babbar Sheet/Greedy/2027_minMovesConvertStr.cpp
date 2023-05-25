// Link : https://leetcode.com/problems/minimum-moves-to-convert-string/
// Time Complexity : O(n)
// Approach-> Sliding window lgao....ek se tb start kro jb X mile and then 3 moves chlo and usme 0 m convert kro and waise hi move krte jao

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minimumMoves(string s)
{
    // Sliding window + greedy lgado
    // Mtlb i will start from begin and move krt jayenge end tk
    //  Harr posibility nhi dekhenge jhan se X dekha wha se lgana start
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'X')
        {
            int j = i;
            while (j < s.length() && j <= i + 2)
            {
                s[i] = 'O';
                j++;
            }
            count++;
            i = j - 1;
        }
    }
    return count;
}

int main()
{

    return 0;
}