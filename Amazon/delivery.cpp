// Link :
// Time Complexity : O(nlgn)
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> delivery(vector<int> locations, vector<int> movedFrom, vector<int> movedTo)
{
    unordered_map<int, int> final;
    for (int i = 0; i < locations.size(); i++)
    {
        final.insert({locations[i], 0});
    }
    for (int i = 0; i < movedFrom.size(); i++)
    {
        final.erase(movedFrom[i]);
        final.insert({movedTo[i], 0});
    }
    vector<int> ans;
    for (auto &i : final)
    {
        ans.push_back(i.first);
    }
    sort(ans.begin(), ans.begin() + ans.size());
    return ans;
}

int main()
{
    vector<int> a = {1, 7, 6, 8};
    vector<int> b = {1, 7, 2};
    vector<int> c = {2, 9, 5};
    vector<int> d = delivery(a, b, c);
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i];
    }

    return 0;
}