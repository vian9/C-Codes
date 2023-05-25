// Link : https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
// Time Complexity : O(nlogn)
// Approach-> Sort krdo and then ye ki neg jha se start h usko positive krte jao and then usko cases dekhlo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int largestSumAfterKNegations(vector<int> &nums, int k)
{
    // sort krega toh negative sbse chota like -4 -3 se left m aayega and positive m bda hoga wo
    sort(nums.begin(), nums.end());
    // ind tells us kha se num negative hona start hua
    int ind = -1;
    // Zero kha se h
    int zero = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            ind = i;
        else if (nums[i] == 0)
            zero = i;
        else
            break;
    }
    int j = 0;
    int start = ind;
    while (k > 0)
    {
        // neg to pos
        if (ind != -1 && j <= ind)
        {
            nums[j] *= -1;
            if (j == ind)
                ind = -1;
            j++;
        }
        // zero exist
        else if (ind == -1 && zero != -1)
        {
            nums[zero] = 0;
        } // no negative no zero
        else if (start == -1 && zero == -1)
        {
            nums[0] *= -1;
        } // negative but k abhi bhi baaki h to least wale ko positive
        else if (start != -1 && start + 1 != nums.size())
        {
            // ab start wla chota h
            if (nums[start] <= nums[start + 1])
            {
                nums[start] *= -1;
            }
            // yha next wla chota h
            else if (nums[start] > nums[start + 1])
            {
                nums[start + 1] *= -1;
            }
        }
        // start se aage number doesn't exist
        else if (start != -1 && start + 1 == nums.size())
        {
            nums[start] *= -1;
        }
        k--;
    }
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    // 2nd solution is array k size -100 to 100 hai...toh 201 element to uska count rkhlo
    // queue se bhi kr skte h
    return sum;
}

int main()
{

    return 0;
}