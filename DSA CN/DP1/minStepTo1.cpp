#include<bits/stdc++.h>
using namespace std;

//Recursive Calls
int minSteps(int n) {
    //Base case agar n <= 1 ho toh
    if (n <= 1) {
        return 0;
    }
    // y and z ko max lelia
    int y = INT_MAX, z = INT_MAX;
    int x = minSteps(n - 1);
    // agar n is divisible by 2 or 3 toh update the count
    if (n % 2 == 0) y = minSteps(n / 2);
    if (n % 3 == 0) z = minSteps(n / 3);
    //Return by adding 1 kuuki humne ek step kia na
    return 1 + min(x, min(y, z));
}

//Memoization
int minStepsHelper(int n, int* ans) {
    //Base Case
    if (n <= 1)
        return 0;

    //Check
    if (ans[n] != -1)
        return ans[n];

    //Recursive call
    int x = minStepsHelper(n - 1, ans);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
        y = minStepsHelper(n / 2, ans);
    if (n % 3 == 0)
        z = minStepsHelper(n / 3, ans);

    //Save output
    ans[n] = min(x, min(y, z)) + 1;
    return ans[n];
}

//Dynamic Programming
int minSteps_2(int n) {
    //Array lelia
    int* ans = new int[n + 1];
    //Initialise array with -1
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return minStepsHelper(n, ans);
}

//Dynamic Programming
int minSteps_3(int n) {
    int* ans = new int[n + 1];
    // Base Case
    ans[0] = 0;
    ans[1] = 0;
    //Iterate krdia
    for (int i = 2; i < n + 1; i++)
    {
        int y = INT_MAX, z = INT_MAX;
        // agar 2 ya 3 se possible to thik and usme savka min we will store
        if (i % 2 == 0)
            y = ans[i / 2];
        if (i % 3 == 0)
            z = ans[i / 3];

        ans[i] = min(ans[i - 1], min(y, z)) + 1;
    }
    return ans[n];
}

int main() {
    // cout << minSteps(7);
    cout << endl;
    cout << minSteps_2(7);
    cout << endl;
    cout << minSteps_3(7);
    return 0;
}