// Link : https://leetcode.com/problems/majority-element/
// Time Complexity : O(n) Space: O(1)
// Approach-> Boyer Moore Voting Algo - Jiska majority aarha +1 kro wrna dusre pr -1 nd since n/2 se jda h +1 hoga hi

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int majorityElement(vector<int> &nums)
{
    //  Boyer-Moore Voting Algorithm - majority will come again with n/2 + 1
    int count = 0;
    int candidate = nums[0];
    for (auto num : nums)
    {
        if (count == 0)
        {
            // candidate bdal dia
            candidate = num;
        }
        // agar same as candidate toh +1 otherwise -1;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

// Bit Manipulation - isme O(1) space m jayega but time complexity O(nlogC)
int majorityElement(vector<int> &nums)
{
    // O(1) space m solve krna h with O(n) time
    // Bit manipulation kr skte h
    // flag m store krenge ki ith item kitna baar aaya h
    int maj_elem = 0;
    for (int i = 0; i < 32; i++)
    {
        // 1 * (2 ^ i)
        // 2i as 1 << i
        int bit = 1 << i;
        // bit will give ith pr 0 h ya 1
        int bit_count = 0;
        for (auto num : nums)
        {
            // ith bit ko check krrhe
            if ((num & bit) != 0)
            {
                bit_count++;
            }
        }
        // 1st LSB se harr bit ko dekhrhe nd jo majority m hai usse save krte jaarhe
        if (bit_count > (nums.size() / 2))
        {
            // ye copy krrhe h element m OR krke
            maj_elem |= bit;
        }
    }

    return maj_elem;
}

// Most easy way is map m ya set m daldo nd freq dekhlo kiska sbse jda h...Space : O(n)
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq.count(nums[i]) > 0)
        {
            freq.at(nums[i]) += 1;
        }
        else
        {
            freq.insert({nums[i], 1});
        }
    }
    unordered_map<int, int>::iterator it = freq.begin();
    int num;
    while (it != freq.end())
    {
        if (it->second > (nums.size() / 2))
        {
            num = it->first;
            break;
        }
        it++;
    }
    return num;
}

int main()
{

    return 0;
}