// Link : https://www.codingninjas.com/codestudio/problems/find-student_3161883?topList=love-babbar-dsa-sheet-problems
// Time Complexity : O(n)
// Approach-> Loop mein iterate krke check krlo jo match krrha.....can't do in O(1) bcoz K se jruri nhi increase
// krrha ho ....at max K se increase hai

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findPos(int N, int K, int H, vector<int> &A)
{
    int pos = -1;
    for (int i = 0; i < N; i++)
    {
        if (A[i] == H)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

int main()
{

    return 0;
}