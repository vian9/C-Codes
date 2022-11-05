#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapsackDP(int n, int val[], int weight[], int W) {
    //2D Array lia h dynamic se
    int** knap = new int* [n];
    for (int i = 0; i < n + 1; i++)
    {
        // ab uska row lia h
        knap[i] = new int[W];
        for (int j = 0; j < W + 1; j++)
        {
            // 0th row nd column m value 0 hoga
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else if (weight[i - 1] <= j && (j - weight[i - 1] >= 0 && j - weight[i - 1] <= W))
            {
                knap[i][j] = max(knap[i - 1][j], knap[i - 1][j - weight[i - 1]] + val[i - 1]);
            } else
                knap[i][j] = knap[i - 1][j];
        }
    }
    int ans = knap[n][W];
    cout << "Maximum profit is : " << knap[n][W] << endl;
    int set[n];
    for (int i = 0; i < n; i++)
    {
        set[i] = 0;
    }
    int j = W;
    for (int i = n; i > 0 && ans > 0; i--)
    {
        //Agar prev me h to wo usse object ko include nhi krenge
        if (knap[i][j] == knap[i - 1][j]) {
            continue;
        } else {
            // ab usse value obj k value = 1 krdia
            set[i - 1] = 1;
            ans = ans - val[i - 1];
            j = j - weight[i - 1];
        }
    }
    cout << "Value weight used: " << endl;
    //print krwa do saaara elements
    for (int i = 0; i < n; i++)
    {
        cout << val[i] << "\t" << weight[i] << "\t" << set[i] << endl;
    }


}

int main() {
    cout << "Enter the number of objects : " << endl;
    int n;
    cin >> n;

    int val[n], wt[n];
    cout << "Enter the value followed by its weight : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i] >> wt[i];
    }

    cout << "Enter the knapsack total Capacity : " << endl;
    int W;
    cin >> W;

    knapsackDP(n, val, wt, W);

    return 0;
}