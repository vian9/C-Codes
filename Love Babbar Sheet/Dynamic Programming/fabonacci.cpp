// Link : https://leetcode.com/problems/fibonacci-number/
// Time Complexity : O(n)
// Approach-> Phle recursive...phir usko save kia kuuki overlapping subproblems....phir tabulation

#include <bits/stdc++.h>
using namespace std;

// Recursive
int fibo_1(int n)
{
    // Base Case
    if (n <= 1)
    {
        return n;
    }
    // PMI lekr aa jayega
    int a = fibo_1(n - 1);
    int b = fibo_1(n - 2);
    return a + b;
}

// Memoisation
int fiboHelper(int n, int *ans)
{
    // Base Case
    if (n <= 1)
        return n;

    // Check ans
    if (ans[n] != -1)
        return ans[n];
    // Calculate
    int a = fiboHelper(n - 1, ans);
    int b = fiboHelper(n - 2, ans);

    ans[n] = a + b;
    return ans[n];
}

int fibo_2(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    return fiboHelper(n, ans);
}

// Dynamic Programming - O(n) - Time....O(n) - Space
int fibo_3(int n)
{
    vector<int> ans(n);
    // Save krdia for bottom up approach
    ans[0] = 0;
    if (n > 0)
        ans[1] = 1;
    // Iterative chala dia
    for (int i = 2; i < n + 1; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}
// Dynamic Programming - O(n) - Time....O(1) - Space
int fibo_3(int n)
{
    if (n < 1)
    {
        return 0;
    }
    // Save krdia for bottom up approach
    int prev2 = 0;
    int prev = 1;
    // Iterative chala dia
    for (int i = 2; i < n + 1; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    cout << fibo_1(5);
    cout << endl;
    cout << fibo_2(5);
    cout << endl;
    cout << fibo_3(5);
    return 0;
}