// Link : https://leetcode.com/problems/find-the-duplicate-number/
// Approach ->O(n)... ek naya vector lia with n-1 size and all value 0.....ab agar 1st time to update it to 1 otherwise wo value return krdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Optimal solution
int findDuplicate(vector<int> &nums)
{
    // Just like LL cycle start detection,,,,hum harr value ko loop lenge
    int slow = 0;
    int fast = 0;
    slow = nums[slow];
    fast = nums[nums[fast]];
    // Jbtk slow and fast na equal ho.....as 0 to n hoga val
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    slow = 0;
    // Ab slow ko fast tk iterate kro
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

// List m daaldia and check krrhe.....jaise hi same tha phle se wo return krdo
int findDuplicate(vector<int> &nums)
{
    set<int> myList;
    for (int i = 0; i < nums.size(); i++)
    {
        if (myList.count(nums[i]) > 0)
        {
            return nums[i];
        }
        else
        {
            myList.insert(nums[i]);
        }
    }
    return -1;
}

int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    // Vector k specific size and with all values 0 initialise krne k tarika
    vector<int> freq(n - 1, 0);
    int retVal = 0;
    for (int i = 0; i < n; i++)
    {
        int value = nums[i];
        if (freq[value - 1] == 0)
        {
            freq[value - 1] = 1;
        }
        else
        {
            retVal = nums[i];
            break;
        }
    }
    return retVal;
}

int main()
{
    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
    }
    return 0;
}