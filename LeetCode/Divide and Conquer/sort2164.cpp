#include <iostream>
#include <vector>
using namespace std;
// some error and very long soln-- never ever write the sorting code....look for short method.

// void mergeSortedo(vector<int> &nums, int si, int mid, int ei)
// {
//     int i = si, j = mid + 1, k = 0;
//     int b[ei + 1];
//     while (i != mid + 1 && j != ei + 1)
//     {
//         if (nums[i] >= nums[j])
//         {
//             b[k] = nums[i];
//             i += 2;
//             k += 2;
//         }
//         else
//         {
//             b[k] = nums[j];
//             j += 2;
//             k += 2;
//         }
//     }

//     while (i != mid + 1)
//     {
//         b[k] = nums[i];
//         i += 2;
//         k += 2;
//     }
//     while (j != ei + 1)
//     {
//         b[k] = nums[j];
//         j += 2;
//         k += 2;
//     }
//     for (int l = si; l < ei; l += 2)
//     {
//         nums[l] = b[l];
//     }
// }

// void mergeSortede(vector<int> &nums, int si, int mid, int ei)
// {
//     int i = 0, j = mid + 1, k = 0;
//     int b[ei + 1];
//     while (i != mid + 1 && j != ei + 1)
//     {
//         if (nums[i] <= nums[j])
//         {
//             b[k] = nums[i];
//             i += 2;
//             k += 2;
//         }
//         else
//         {
//             b[k] = nums[j];
//             j += 2;
//             k += 2;
//         }
//     }

//     while (i != mid + 1)
//     {
//         b[k] = nums[i];
//         i += 2;
//         k += 2;
//     }
//     while (j != ei + 1)
//     {
//         b[k] = nums[j];
//         j += 2;
//         k += 2;
//     }
//     for (int l = 0; l < ei; l += 2)
//     {
//         nums[l] = b[l];
//     }
// }

// void mergeSort(vector<int> &nums, int si, int ei)
// {
//     int mide = 0;
//     int mido = 0;
//     bool flag = true;
//     if (ei % 2 == 0)
//     {
//         mide = (si + ei) / 2;
//         mido = (si + 1 + ei - 1) / 2;
//     }
//     else
//     {
//         flag = false;
//         mide = (si + ei - 1) / 2;
//         mido = (si + 1 + ei) / 2;
//     }
//     if (flag)
//     {
//         mergeSort(nums, si, mide);
//         mergeSort(nums, mide + 1, ei);
//         mergeSortede(nums, si, mide, ei);
//         mergeSort(nums, si + 1, mido);
//         mergeSort(nums, mido + 1, ei - 1);
//         mergeSortedo(nums, si + 1, mido, ei - 1);
//     }
//     else
//     {
//         mergeSort(nums, si, mide);
//         mergeSort(nums, mide + 1, ei - 1);
//         mergeSortede(nums, si, mide, ei - 1);
//         mergeSort(nums, si + 1, mido);
//         mergeSort(nums, mido + 1, ei);
//         mergeSortedo(nums, si + 1, mido, ei);
//     }
// }

// vector<int> sortEvenOdd(vector<int> &nums)
// {
//     int si = 0;
//     int ei = nums.size() - 1;
//     mergeSort(nums, si, ei);
//     return nums;
// }

// optimal soln
vector<int> sortEvenOdd(vector<int> &nums)
{
    vector<int> nums1;
    int m = nums.size();
    vector<int> nums2;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
        {
            nums1.push_back(nums[i]);
        }
        else
        {
            nums2.push_back(nums[i]);
        }
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    nums.clear();
    int j = 0, k = nums2.size() - 1;
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            nums.push_back(nums1[j]);
            j++;
        }
        else
        {
            nums.push_back(nums2[k]);
            k--;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {4, 1, 2, 3};
    sortEvenOdd(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }

    return 0;
}