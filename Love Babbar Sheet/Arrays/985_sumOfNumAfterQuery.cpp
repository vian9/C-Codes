// Link : https://leetcode.com/problems/sum-of-even-numbers-after-queries/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int sumOfEven(vector<int> &nums)
{
    int mod = 100000007;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
            sum += nums[i];
        sum = sum % mod;
    }
    return sum;
}

vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
{
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        int ind = queries[i][1];
        nums[ind] = queries[i][0] + nums[ind];
        ans.push_back(sumOfEven(nums));
    }
    return ans;
}

int main()
{

    return 0;
}