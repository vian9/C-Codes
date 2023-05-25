// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int distMoney(int money, int children)
{
    if (money < children)
    {
        return -1;
    }
    money -= children;
    int num = money / 7;
    int rem = money % 7;
    int remChild = children - num;
    if (remChild > 0)
    {
        rem = rem / remChild;
    }
    if (rem == 3 && remChild == 1)
        num--;
    if (remChild == 0 && rem > 1)
    {
        num--;
    }
    if (num >= 0)
        return num;
    else
        return 0;
}

int maximizeGreatness(vector<int> &nums)
{
    // Max elements uske alawa lete jao
    unordered_map<int, int> index;
    vector<int> maxi;
    for (int i = 0; i < nums.size(); i++)
    {
        index[nums[i]]++;
        maxi.push_back(nums[i]);
    }
    int ans = 0;
    sort(maxi.begin(), maxi.end());
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     int ind = upper_bound(maxi.begin(), maxi.end(), nums[i]) - maxi.begin();
    //     if ((ind < maxi.size() && maxi[ind] > nums[i]) && index.count(maxi[ind]) > 0)
    //     {
    //         cout<<ind<<" "<<index[maxi[ind]]<<" "<<nums[i]<<endl;
    //         index[maxi[ind]]--;
    //         vector<int>::iterator it;
    //         it = maxi.begin() + ind;
    //         maxi.erase(it);
    //         ans += 1;
    //     }
    // }
    vector<int> ansi(nums.size());
    ansi[nums.size() - 1] = 0;
    // AGar right k baarabar h to same val otherwise kitna right mein elements usse
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (maxi[i] == maxi[i + 1])
        {
            ansi[i] = ansi[i + 1];
        }
        else
        {
            ansi[i] = nums.size() - 1 - i;
        }
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        cout << ansi[i] << endl;
        if (ansi[i] > 0)
        {
            // Agar ans k barbar h ya bada h mtlb consider hogya h
            if (ans < ansi[i])
            {
                ans++;
            }
        }
    }
    return ans;
}

long long findScore(vector<int> &nums)
{
    priority_queue<pair<int, int>, vector<int>, greater<int>> pq;
    int n = nums.size();
    unordered_map<int, bool> indi;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push({nums[i], i});
        indi[i] = false;
    }
    long long ans = 0;
    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        int val = top.first;
        int ind = top.second;
        if (ind != 0 && ind != n)
        {
            ans += val;
            indi[ind] = true;
            indi[ind - 1] = true;
            indi[indi + 1] = true;
        }
    }
}

int main()
{

    return 0;
}