#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countPairs(vector<int> &nums, int k)
{
    int m = nums.size();
    int count = 0;
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (nums[i] == nums[j] && (i * j) % k == 0)
            {
                count++;
                continue;
            }
            else
            {
                continue;
            }
        }
    }
    return count;
}

int main()
{
    vector nums = {5, 5, 9, 2, 5, 5, 9, 2, 2, 5, 5, 6, 2, 2, 5, 2, 5, 4, 3};

    int k = 7;
    cout << countPairs(nums, k) << endl;

    return 0;
}