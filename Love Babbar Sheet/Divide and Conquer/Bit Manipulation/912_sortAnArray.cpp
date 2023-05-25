// Link : https://leetcode.com/problems/sort-an-array/
// Time Complexity : O(logn) & Space : O(n)
// Approach-> Merge Sort lgaya h...O(1) k liye use heap sort

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void mergeSortArray(int low, int mid, int high, vector<int> &nums)
{
    int i = low, j = mid + 1;
    vector<int> ans;
    // Tbtk jbtk dono mein se koi ek array over na ho jaye
    while (i < mid + 1 && j < high + 1)
    {
        if (nums[i] <= nums[j])
        {
            ans.push_back(nums[i]);
            i++;
        }
        else
        {
            ans.push_back(nums[j]);
            j++;
        }
    }
    // ab dusra wla to sorted hi rhega as merge krna tha sorted array to just copy
    while (i < mid + 1)
    {
        ans.push_back(nums[i]);
        i++;
    }
    while (j < high + 1)
    {
        ans.push_back(nums[j]);
        j++;
    }
    int l = 0;
    // ab ye original array mein copy krdia
    for (int k = low; k < high + 1; k++)
    {
        nums[k] = ans[l];
        l++;
    }
}

void mergeSort(int low, int high, vector<int> &nums)
{
    int mid = (high - low) / 2 + low;
    if (low >= high)
        return;

    // Isko tordo jbtk 1 tk na aa jaye to make 2 comparisions
    mergeSort(low, mid, nums);
    mergeSort(mid + 1, high, nums);
    mergeSortArray(low, mid, high, nums);
}

vector<int> sortArray(vector<int> &nums)
{
    // Merge sort
    mergeSort(0, nums.size() - 1, nums);
    return nums;
}

int main()
{

    return 0;
}