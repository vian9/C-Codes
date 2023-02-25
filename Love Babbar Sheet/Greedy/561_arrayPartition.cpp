// Link : https://leetcode.com/problems/array-partition/description/
// Time Complexity : O(nlogn)
// Approach-> Sort krke order m pair lo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// sort krdo and order m pair lelo....kuuki min jo h wo barbad nhi krna h toh greedy hokr lo max dega
int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2)
    {
        sum += nums[i];
    }
    return sum;
}

int main()
{

    return 0;
}