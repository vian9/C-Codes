// Link : https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1
// Approach -> O(n).....ek array lia usme phle positive push kia phir negative and finally purana array updated

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void segregateElements(int arr[], int n)
{
    // array le lenge jisme hum push krte jayenge phle positibe phir negative
    int countneg = 0;
    int neg[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            neg[j] = arr[i];
            j++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg[j] = arr[i];
            j++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = neg[i];
    }
}

int main()
{
    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
    }
    return 0;
}