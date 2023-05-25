// Link : https://leetcode.com/problems/3sum/
// Time Complexity : O(n^2).....brute force will be O(n^3)
// Approach-> Sort krdia....ab ith ko centre maan lo and left and right are two pointers.....since it's sorted
// to binary search lagayenge.....uske liye just check sum and push.....ab sum 0 horha h toh left ko badhao jbtk
// left ya phir diff na ho ya phir end na ho taki elements repeat na ho and usse ith element k liye diff possible aa jaye

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.begin() + nums.size());
    int left = 1;
    int right = nums.size() - 1;
    // 2loop rhega hi kuuki vector mein vector iterate krne k liye chahiye
    for (int i = 0; i < nums.size(); i++)
    {
        left = i + 1;
        right = nums.size() - 1;
        // Agar ith same h toh move krega skipping loop
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        while (left < right)
        {
            if (nums[left] + nums[right] + nums[i] == 0)
            {
                // Vector with type vector mein vector kaise push krte h
                ans.push_back({nums[left], nums[right], nums[i]});
                left++;
                // Taki agar repeated h toh wo push nhi krenge possible with ith as centre
                while (left < right && nums[left] == nums[left - 1])
                {
                    left++;
                }
            }
            else if (nums[left] + nums[right] + nums[i] > 0)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}