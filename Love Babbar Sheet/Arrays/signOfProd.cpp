// Link : https://leetcode.com/problems/sign-of-the-product-of-an-array/
// Time Complexity : O(n)
// Approach-> Since sign btana hai to prod ko store krne k jrurt nhi bas 1 ya -1 se kaam chal jayega.....so prod ko nkalo
// and har iteration mein check its sign....0 hua toh return otherwise just write prod as 1 ya -1.
// Ye sign prod mein bas rkh rhe kuuki prod store nhi kr paate aise aur hume bas sign se mtlb h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int arraySign(vector<int> &nums)
{
    int prod = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        prod = prod * nums[i];
        // Isko baad mein issliye kuuki agar bas nums mein ek element 0 rha to neeche check krke update krdega nd return
        // Prod operation k upar rehta toh 0 return nhi kr paata kuuki bas 1 element hai toh aage loop jata hi nhi
        if (prod == 0)
        {
            return 0;
        }
        else if (prod > 0)
            prod = 1;
        else
            prod = -1;
    }
    if (prod > 0)
        return 1;
    else
        return -1;
}

int main()
{

    return 0;
}