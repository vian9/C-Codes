// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > a.second;
}

vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
{
    // vector pair mein value and index
    vector<pair<int, int>> vt;
    for (int i = 0; i < score.size(); i++)
    {
        vt.push_back({score[i][k], i});
    }
    sort(vt.begin(), vt.end(), compare());
    vector<vector<int>> ans;
    for (int i = 0; i < vt.size(); i++)
    {
        vector<int> rows;
        rows = score[vt[i].second];
        ans.push_back(rows);
    }
    return ans;
}

int main()
{

    return 0;
}