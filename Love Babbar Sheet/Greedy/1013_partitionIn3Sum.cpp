// Link : https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
// Time Complexity : O(n)
// Approach-> 3 ka sum kitna hoga dekhlo and then usse tm nikallo kitna baar wo sum aarha h...ye jb bhi 3 k sum hoga will include even odd or all odd and could be partitioned

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool canThreePartsEqualSum(vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    if (sum % 3 != 0)
        return false;
    // Agar fully divisible h by 3 krdo
    sum /= 3;
    // Ab dekho kitna baar 3 ka aarha h
    int curr = 0;
    int ind = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        curr += arr[i];
        if (curr == sum)
        {
            ind++;
            curr = 0;
        }
    }
    // Agar 3 se jada to return true like agar target sum zero h toh 3 baar se jada hoga
    if (ind >= 3)
        return true;
    return false;
}

int main()
{

    return 0;
}