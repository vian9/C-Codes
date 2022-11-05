// Link : https://leetcode.com/problems/reshape-the-matrix/
// Time Complexity : O(n)
// Approach-> Imp is how to declare a 2D Matrix.....uske baad row and column ek iterator se kaise access kroge bcoz O(n) mein krna h
// So Row and Column k liye i ko iterate krwa kr and i/c gives row no and i%c gives column no

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    // To declare 2 D Matrix of specific size and value
    vector<vector<int>> ans = vector<vector<int>>(r, vector<int>(c, 0));
    int n = mat.size();
    int m = mat[0].size();
    if (r * c != m * n)
        return mat;
    for (int i = 0; i < r * c; i++)
    {
        // i jitna badhega by c se divide hokr row de dega and uska remainder column de dega
        ans[i / c][i % c] = mat[i / m][i % m];
    }
    return ans;
}

int main()
{

    return 0;
}