// Link : https://practice.geeksforgeeks.org/problems/subset-sums2234/1
// Time Complexity : O(2^n)
// Approach-> Recursion use kiya....Pick Not Pick

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void subset(vector<int> &arr, vector<int> &ans, int N, int ind, int sum)
{
    // Base Case jaise hi aagya woh sum push krdo
    if (ind == N)
    {
        ans.push_back(sum);
        return;
    }
    // Ab yeh harr case lakr dega subset ka
    // Pick kro
    subset(arr, ans, N, ind + 1, sum + arr[ind]);
    // Not Pick kro Subset
    subset(arr, ans, N, ind + 1, sum);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    subset(arr, ans, N, 0, 0);
    return ans;
}

int main()
{

    return 0;
}