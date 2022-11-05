// Link : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Time Complexity : O(n)
// Approach-> 2 Pointer Approach......2 pointer lia and ek left se and ek right se move kia jbtk overlap na kre
// Agar sum se jada h to right ko kaam kro and kaam h to left ko badhao

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> res;
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right)
    {
        if (numbers[left] + numbers[right] == target)
        {
            res.push_back(left + 1);
            res.push_back(right + 1);
            break;
        }
        else if (numbers[left] + numbers[right] < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return res;
}

int main()
{

    return 0;
}