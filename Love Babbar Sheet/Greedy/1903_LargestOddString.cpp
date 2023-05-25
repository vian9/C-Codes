// Link : https://leetcode.com/problems/largest-odd-number-in-string/
// Time Complexity : O(n)
// Approach-> Last se string start kro and jaise hi odd aa jaye to wo start se curr tk odd h and just return it...it will be max

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string largestOddNumber(string num)
{
    // yhi aarha check kro agar odd h to dalte jao and nhi h to update and move
    //  kuuki substring h to continous lenge
    //  Ab string integer se bahar jaarha to aise odd check krlo
    //  bs yhi sahi rkhna tha ki kha se hum string start krrhe h

    // Last digit odd ho gya to
    if (((num[num.length() - 1]) - '0') % 2 != 0)
        return num;

    for (int i = num.length() - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 != 0)
        {
            return num;
        }
        else
        {
            // wrna wo index ko erase krte jao
            num.erase(i, 1);
        }
    }
    return "";
}

int main()
{

    return 0;
}