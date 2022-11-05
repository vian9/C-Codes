#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    int total = 0;
    // sbse kaam coin lena h to min coin se lenge
    // phir jitna bacha wo hum baaki coin se lenge
    int m = coins.capacity();
    sort(coins, coins + m);
    int sum = 0;
    int left = amount;
    for (int i = m - 1; i >= 0; i--)
    {
        if (left / coins[i] != 0 && left != 0)
        {
            total += (left / coins[i]);
            sum = (left / coins[i]) * coins[i];
            left = amount - sum;
        }
    }

    if (sum == amount)
    {
        return total;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<int> coins;
    coins.push_back(1);
    int amt = ;
    cout << coinChange(a, amt) << endl;

    return 0;
}