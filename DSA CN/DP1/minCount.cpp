#include<bits/stdc++.h>
using namespace std;

//Recursive
int minCount(int n) {
    if (n <= 1)
        return 1;

    int num = sqrt(n);
    int minCounti = INT_MAX;
    for (int i = 1; i <= num; i++)
    {
        int p = i * i;
        int c = -1;
        if (n - p != 0) c = minCount(n - p);
        else c = 0;
        minCounti = min(minCounti, c + 1);
    }
    return minCounti;
}

int main() {
    cout << minCount(9);
    cout << endl;
    // cout << minSteps_2(7);
    // cout << endl;
    // cout << minSteps_3(7);
    return 0;
}