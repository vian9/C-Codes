// Link : https://leetcode.com/problems/maximum-product-subarray/
// Time Complexity : O()
// Approach-> It is too based Kudane's Algo ki agar 0 aagya toh phirse 0 se start
// Another Approach can be ki left se prod lo and right se prod lo ek var mein aur beech mein 0 aaye toh prod phir se 1 hoga
// if zeroPresent toh max of leftProd,rightProd, 0 otherwise only max of leftProd,rightProd will be ans.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxProduct(vector<int> &nums)
{
    int prod1 = nums[0], prod2 = nums[0], result = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int temp = max({nums[i], nums[i] * prod1, nums[i] * prod2});
        prod2 = min({nums[i], nums[i] * prod1, nums[i] * prod2});
        prod1 = temp;
        result = max(prod1, result);
    }
    return result;
}

int main()
{

    return 0;
}