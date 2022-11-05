// VVVI
// Link : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Time Complexity : O(nlogn).....logn for binary search and usme n times matrixSolve worst case
// Approach-> Binary Search between elements laga skte h but hume position chahiye to uske liye hum mid k position nikalte h
// agar ko k se kaam h toh low badhao otherwise high ghatao
// Ab count k liye i and j agar edge par match krrha toh check current element mid se bada h ya chota
// bada h toh row ghatao and chota h toh count mein add krte jao

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int matrixSolve(vector<vector<int>> &matrix, int mid)
{
    int n = matrix.size();
    int i = n - 1;
    int j = 0;
    int count = 0;
    while (i >= 0 && j < n)
    {
        if (matrix[i][j] > mid)
            i--;
        else
        {
            // kuuki yeh move krrha h pechla row mein jbtk wo row over na hojaye....toh rowNo+1 utna baar will give the position
            count += (i + 1);
            j++;
        }
    }
    return count;
}

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int posi = matrixSolve(matrix, mid);
        if (posi < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{

    return 0;
}