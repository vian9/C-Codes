// VVI
// Link : https://leetcode.com/problems/product-of-array-except-self/
// Link : https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1
// Time Complexity : O(n) for both solution
// Approach-> One can be mathematical approach jisme if there is only one zero toh usse 0 k alawa savme 0 agar 2 zero
// rha toh savme zero otherwise saara k product / nums[i] will give the answer
// Other Solution is ek baar aage se product lete jao and pushback in vector.....phir peeche se product lo and push

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> productExceptSelf(vector<int> &nums)
{
    // 1st Solution -- Mathematical Approach
    vector<int> product(nums.size());
    int val = 1;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            val *= (nums[i]);
        }
        else
        {
            count++;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (count > 1)
        {
            product[i] = 0;
        }
        else if (count == 0)
        {
            product[i] = (val / nums[i]);
        }
        else if (count == 1 && nums[i] != 0)
        {
            product[i] = 0;
        }
        else
        {
            product[i] = val;
        }
    }
    return product;

    // 2nd Solution -- Logical Approach
    vector<int> ans(nums.size());
    int product = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] = product;
        product = (product * nums[i]);
    }
    product = 1;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        ans[i] = (product * ans[i]);
        product = (product * nums[i]);
    }
    return ans;
}

int main()
{

    return 0;
}