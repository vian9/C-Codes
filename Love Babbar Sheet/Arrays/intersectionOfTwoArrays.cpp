// Link : https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Time Complexity : O(n)
// Approach-> Map mein ek ka frequency store krdia....ab dusra array pr iterate kro and check agar map mein h
// toh push back in vector and uska frequency decrease krdo.....aur agar freq ==0 hai to erase krdo wo map se

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    unordered_map<int, int> freq;
    for (int i = 0; i < nums1.size(); i++)
    {
        freq[nums1[i]]++;
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        if (freq.count(nums2[i]) > 0)
        {
            ans.push_back(nums2[i]);
            freq[nums2[i]]--;
            if (freq[nums2[i]] == 0)
            {
                freq.erase(nums2[i]);
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}