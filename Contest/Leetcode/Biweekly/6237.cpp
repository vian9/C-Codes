#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void pop_front(vector<T> &vec)
{
    assert(!vec.empty());
    vec.front() = move(vec.back());
    vec.pop_back();
}

int distinctAverages(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    unordered_map<float, int> freq;
    float avg = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int n = nums.size();
        avg = (nums[i] + nums[n - i - 1]) / 2;
        freq[avg]++;
        }

    return freq.size();
}

int main()
{
    vector<int> ans;
    for (int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        ans.push_back(n);
    }
    cout << distinctAverages(ans);

    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
    }
    return 0;
}