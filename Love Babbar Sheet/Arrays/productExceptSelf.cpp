// VVI
// Link : https://www.codingninjas.com/codestudio/problems/product-of-array-except-self_630271?topList=love-babbar-dsa-sheet-problems
// Link : https://leetcode.com/problems/product-of-array-except-self/
// Time Complexity : O(n)
// Approach-> Loop lelia and usme ab zero dekhlia and sab k multiply value nikal lia and then case k dhyan rkhlo
// This approach is not able to handle big cases due to multiply issue.....alag se multiply function to handle it
// Optimal method in same O(n) will be: ek baar loop se 0 to i-1 tk multiply kro and update kro...phir peeche se n-1 to i+1 multiply and update
// VVI not for logic but for handling big numbers.....alag function ko handle krne do wo operation
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int multiply(int a, int b)
{
    int mod = 1e9 + 7;
    long long ret = a % mod;
    ret *= (b % mod);
    ret = ret % mod;
    return ret;
}

int *getProductArrayExceptSelf(int *arr, int n)
{
    // int *product = new int[n];
    // long long int val = 1;
    // int count = 0;
    // long long int mo = 1e9 + 7;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] != 0)
    //     {
    //         val *= (arr[i] % mo);
    //     }
    //     else
    //     {
    //         count++;
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     if (count > 1)
    //     {
    //         product[i] = 0;
    //     }
    //     else if (count == 0)
    //     {
    //         arr[i] = arr[i] % mo;
    //         product[i] = (val / arr[i]) % mo;
    //     }
    //     else if (count == 1 && arr[i] != 0)
    //     {
    //         product[i] = 0;
    //     }
    //     else
    //     {
    //         product[i] = val;
    //     }
    // }
    // return product;

    // Optimal method for big numbers
    int *output = new int[n];
    int product = 1;

    for (int i = 0; i < n; ++i)
    {
        output[i] = product;
        product = multiply(product, arr[i]);
    }

    product = 1;

    for (int i = n - 1; i >= 0; --i)
    {
        output[i] = multiply(product, output[i]);
        product = multiply(product, arr[i]);
    }

    return output;
}

int main()
{

    return 0;
}