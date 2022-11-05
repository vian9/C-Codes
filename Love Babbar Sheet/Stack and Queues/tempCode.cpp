 vector<int> ans;
    deque<int> comp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!comp.empty() && comp.front() == i - k)
        {
            comp.pop_front();
        }
        while (!comp.empty() && nums[comp.back()] <= nums[i])
        {
            comp.pop_back();
        }
        if (i >= k - 1)
        {
            ans.push_back(nums[comp.front()]);
        }
    }
    return ans;