// Link : https://leetcode.com/problems/move-zeroes/
// Time Complexity : O(n) and O(1) space
// Approach-> Agar 0 hua to delete krdiaa and phir finally at the end insert krdia 0

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void moveZeroes(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return;
    }
    int count = 0;
    int n = nums.size();
    for (auto i = nums.begin(); i < nums.end(); ++i)
    {
        if (*i == 0)
        {
            count++;
            nums.erase(i);
            // yeh i-- kuuki ye wla delete hogya h pchle wale pr jayenge and wahan se ++i se next pr
            i--;
        }
    }

    if (count != 0)
    {
        nums.insert(nums.end(), count, 0);
    }
}

// Less line and O(n) with less time
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[j], nums[i]);
            i++;
        }
    }
}

int main()
{

    return 0;
}