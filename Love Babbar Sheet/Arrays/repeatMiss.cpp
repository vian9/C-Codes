// Link : https://www.codingninjas.com/codestudio/problems/find-the-repeating-and-missing-number_1062727?topList=love-babbar-dsa-sheet-problems
// Time Complexity : O(n)
// Approach-> Savka frequency likhlia ek vector mein and jaise hi repeat hua usse lelia.....ab phir vector of
// frequency pr iterate to check ki kaun missing h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    int n = nums.size();
    vector<int> freq(n, 0);
    int repeat = -1;
    int miss = -1;
    for (int i = 0; i < n; i++)
    {
        if (freq[nums[i] - 1] == 0)
        {
            freq[nums[i] - 1] = 1;
        }
        else if (freq[nums[i] - 1] == 1)
        {
            repeat = nums[i];
            freq[nums[i] - 1] += 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (freq[i] == 0)
        {
            miss = i + 1;
        }
    }
    vector<int> ans;
    ans.push_back(repeat);
    ans.push_back(miss);
    return ans;
}

int main()
{

    return 0;
}