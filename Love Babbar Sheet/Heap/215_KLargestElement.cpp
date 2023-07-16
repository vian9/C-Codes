// Link : https://leetcode.com/problems/kth-largest-element-in-an-array/
// Time Complexity : O(n) avg case
// Approach-> Quick sort se max se min m sort kro and jaise hi pivot pos k pr aa jaye whi hoga return it

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[low];
    int pivotPos = low;
    int i = low + 1, j = high;
    // hum sort krrhe h max se min tk
    while (i <= j)
    {
        // toh agar pivot se chota and wha bada to replace
        if (nums[i] < pivot && nums[j] > pivot)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        else if (nums[i] >= pivot)
        {
            i++;
        }
        else if (nums[j] <= pivot)
        {
            j--;
        }
    }
    // Ab finally ye pivot ko j wale se swap krdo taaki ye pivot apne pos pr aa jaye
    swap(nums[low], nums[j]);
    return j;
}

// will use quick sort algo to sort until kth pivot pos...jaise hi k milgya return
int findKthLargest(vector<int> &nums, int k)
{
    int low = 0, high = nums.size() - 1;
    int n = nums.size();
    int val = 0;
    // Infinite loop
    while (1)
    {
        int pivotPos = partition(nums, low, high);
        // Sort is max to min value to 0 index k liye k-1 se barabar aa jaye to
        if (pivotPos == k - 1)
        {
            val = nums[pivotPos];
            break;
        }
        // Pivotpos abhi jada bada h to high ko badlo
        if (pivotPos > k - 1)
        {
            high = pivotPos - 1;
        }
        // ya low ko badlo
        else
        {
            low = pivotPos + 1;
        }
    }
    return val;
}

// Using Priority queue... O(k+(n-k)*log(k)) insertion and Space is exceeding
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        nums.push_back(nums[i]);
    }
    for (int i = 1; i < nums.size() - k; i++)
    {
        pq.pop();
    }
    return pq.top();
}

// Sort krdo....O(NlogN)
int findKthLargest(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int main()
{

    return 0;
}