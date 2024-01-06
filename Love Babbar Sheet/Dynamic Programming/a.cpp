#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    Function call to merge two partitions
    Such that the merged array is sorted
*/
int merge(vector<int> &pref, int left, int mid, int right)
{

    vector<int> ref(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;
    int cnt = 0;
    int inversion_count = 0;

    while (i <= mid && j <= right)
    {

        if (pref[i] <= pref[j])
        {
            ref[k++] = pref[i++];
        }
        else
        {
            // Counting inversions
            inversion_count += (mid - i + 1);
            ref[k++] = pref[j++];
        }
    }

    while (i <= mid)
    {
        ref[k++] = pref[i++];
    }

    while (j <= right)
    {
        ref[k++] = pref[j++];
    }

    k = 0;
    for (int itr = left; itr <= right; itr++)
    {
        pref[itr] = ref[k++];
    }
    return inversion_count;
}

/*
    Function to calculate number of
    Inversions in a given array using
    the merge sort technique
*/
int count_inversions(vector<int> &pref, int left, int right)
{

    int left_count = 0, right_count = 0, merge_count = 0;

    if (left < right)
    {

        int mid = (left + right) / 2;
        left_count = count_inversions(pref, left, mid);
        right_count = count_inversions(pref, mid + 1, right);
        merge_count = merge(pref, left, mid, right);
    }

    return left_count + right_count + merge_count;
}

/*
    Function to count the number of
    Substrings that contains more 1s than 0s
*/
int count_substrings(string &s, int n)
{

    vector<int> pref(n, 0);

    // Putting 1 for '1' and -1 for '0' as explained in the approach
    for (int i = 0; i < n; i++)
    {

        if (s[i] == '0')
        {
            pref[i] = -1;
        }
        else
        {
            pref[i] = 1;
        }
    }

    // Converting into prefix sum array
    for (int i = 1; i < n; i++)
    {
        pref[i] += pref[i - 1];
    }

    // Stores the count of valid substrings
    int total = 0;
    for (int i = 0; i < n; i++)
    {

        // If pref[i] > 0 means string from 0 to i is a valid one
        if (pref[i] > 0)
        {
            ++total;
        }
    }

    // Reversing the given array
    int j = n - 1;
    for (int i = 0; i < j; i++, j--)
    {
        swap(pref[i], pref[j]);
    }

    total += count_inversions(pref, 0, n - 1);
    return total;
}

// Driver Code
int main()
{

    // Length of the given string
    int n = 5;

    // Given input string
    string s = "11010";

    // Function Call
    int ans = count_substrings(s, n);

    cout << ans << endl;
    return 0;
}