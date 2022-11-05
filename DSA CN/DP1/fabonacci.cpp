#include<bits/stdc++.h>
using namespace std;

//Recursive
int fibo_1(int n) {
    //Base Case
    if (n <= 1) {
        return n;
    }
    //PMI lekr aa jayega
    int a = fibo_1(n - 1);
    int b = fibo_1(n - 2);
    return a + b;
}

//Memoisation
int fiboHelper(int n, int* ans) {
    //Base Case
    if (n <= 1)
        return n;

    //Check ans
    if (ans[n] != -1)
        return ans[n];
    //Calculate
    int a = fiboHelper(n - 1, ans);
    int b = fiboHelper(n - 2, ans);

    ans[n] = a + b;
    return ans[n];
}

int fibo_2(int n) {
    int* ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    return fiboHelper(n, ans);
}

//Dynamic Programming
int fibo_3(int n) {
    int* ans = new int[n + 1];
    //Save krdia for bottom up approach
    ans[0] = 0;
    ans[1] = 1;
    //Iterative chala dia
    for (int i = 2; i < n + 1; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}

int main() {
    cout << fibo_1(5);
    cout << endl;
    cout << fibo_2(5);
    cout << endl;
    cout << fibo_3(5);
    return 0;
}