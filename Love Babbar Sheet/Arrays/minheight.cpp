// Link : https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
// Approach is greedy in O(nlogn) time....cant be reduced further as it requires sorting

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int getMinDiff(int arr[], int n, int k)
{
    // Approach -> Greedy lagana h, first sort kro and then max difference ans m daal do jo 0th and n-1th element k diff hoga
    // ab either u can go 1 mein add krke and 2nd m subtract krke diff nikalkr compare krke
    // and ab max and min dekhlo value k......sorted h to neche value mein add krke max se compare krenge and bada value mein subtract krke min se

    // int maxi = 0;
    // int mini = 0;
    // sort(arr, arr + n);
    // maxi = arr[n - 1] - k;
    // mini = arr[0] + k;
    // int ans = arr[n - 1] - arr[0];
    // int mn, mx;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     mx = max(maxi, arr[i] + k);
    //     mn = min(mini, arr[i + 1] - k);
    //     if (mn < 0)
    //     {
    //         continue;
    //     }
    //     ans = min(ans, (mx - mn));
    // }
    // return ans;

    // Method 2 by sorting similar just simpler
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0]; // Maximum possible height difference

    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - k < 0) // if on subtracting k we got negative then continue
            continue;
        tempmin = min(arr[0] + k, arr[i] - k);         // Minimum element when we
                                                       // add k to whole array
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k); // Maximum element when we
                                                       // subtract k from whole array
        ans = min(ans, tempmax - tempmin);
    }
    return ans;
}

int main()
{
    int n = 10;
    int k = 5;
    int arr[n] = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
    cout << getMinDiff(arr, n, k) << endl;
    return 0;
}