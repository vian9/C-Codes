// Link : https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
// Link : https://leetcode.com/problems/majority-element/
// Time Complexity : O(n)
// Approach-> Map lia and usme freq store krlia and jiska sbse jada freq last me return

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// LeetCode -- There must be an majority element
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq.count(nums[i]) > 0)
        {
            freq.at(nums[i]) += 1;
        }
        else
        {
            freq.insert({nums[i], 1});
        }
    }
    unordered_map<int, int>::iterator it = freq.begin();
    int num;
    while (it != freq.end())
    {
        if (it->second > (nums.size() / 2))
        {
            num = it->first;
            break;
        }
        it++;
    }
    return num;
}

// GeeksforGeeks -- return -1 if no element exists
int majorityElement(int a[], int size)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < size; i++)
    {
        if (freq.count(a[i]) > 0)
        {
            freq.at(a[i]) += 1;
        }
        else
        {
            freq.insert({a[i], 1});
        }
    }
    unordered_map<int, int>::iterator it = freq.begin();
    int num = -1;
    while (it != freq.end())
    {
        if (it->second > (size / 2))
        {
            num = it->first;
            break;
        }
        it++;
    }
    return num;
}

int main()
{

    return 0;
}