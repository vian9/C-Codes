// Link : https://leetcode.com/problems/matrix-diagonal-sum/submissions/
// Time Complexity : O(n)
// Approach-> Instead of iterating row and column taking O(n^2)......Followed 2 Pointer Approach
// 2 Pointer lia i and j and ek left se and right se move krwaya and sum leta gya
// Agar no of rows and columns odd hai toh ek common match hoga to n-1 lelia and if it's even to centre wala minus krdia
// kuuki 2 baar add kia

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int diagonalSum(vector<vector<int>> &mat)
{
    int sum = 0;
    int j = 0;
    int k = mat.size() - 1;
    for (int i = 0; i < mat.size(); i++)
    {
        sum += (mat[i][j] + mat[i][k]);
        j++;
        k--;
    }
    // n agar odd hai tbhi common hoga toh n-1 is even and phir common wala minus krdia
    int n = mat.size() - 1;
    if (n % 2 == 0)
        sum -= mat[n / 2][n / 2];

    return sum;
}

int main()
{

    return 0;
}