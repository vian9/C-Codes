bool compare(int a, int b)
{
    return a > b;
}

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
    sort(nums2.begin(), nums2.end(), compare());
    nums.clear();
    int j = 0, k = 0;
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            nums.push_back(nums1[j]);
            j++;
        }
        else
        {
            nums.push_back(nums1[k]);
            k++;
        }
    }
    return nums;
}