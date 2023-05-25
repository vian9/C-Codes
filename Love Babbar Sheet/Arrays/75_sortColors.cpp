// Link : https://leetcode.com/problems/sort-colors/
// Time Complexity : O(n)
// Approach-> Dutch National Flag Algo (3 Pointer Approach)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void sortColors(vector<int> &nums)
{
    // Three Pointer approach
    int start = 0;
    int n = nums.size();
    int end = n - 1;
    int mid = 0;
    // start and mid aage se chlega......end will move from last
    // start will be on jahan last 0 aaya uske baad
    while (mid <= end)
    {
        // agar mid aagya 0 toh start and mid ko swap and start and mid aage
        if (nums[mid] == 0)
        {
            swap(nums[start], nums[mid]);
            start += 1;
            mid++;
        }
        else if (nums[mid] == 1)
        { // agar mid 1 hai toh mid aage badhao
            mid++;
        }
        else
        {
            // swap 2 mein with mid and end.....2 ko last mein bhejrhe
            swap(nums[mid], nums[end]);
            end--;
        }
    }

    // Brute Force approach - not recommended
    // int count0 = 0;
    // int count1 = 0;
    // int count2 = 0;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] == 0)
    //         count0++;
    //     else if (nums[i] == 1)
    //         count1++;
    //     else
    //         count2++;
    // }
    // int i = 0;
    // while (count0--)
    // {
    //     nums[i] = 0;
    //     i++;
    // }
    // while (count1--)
    // {
    //     nums[i] = 1;
    //     i++;
    // }
    // while (count2--)
    // {
    //     nums[i] = 2;
    //     i++;
    // }
}

int main()
{

    return 0;
}