// Hackon with Amazon

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> magicaltube(int Q, vector<pair<int, int>> queries)
{
    vector<int> removed;
    map<int, int> freq;
    vector<int> listss;
    for (int i = 0; i < queries.size(); i++)
    {
        if (queries[i].first == 1)
        {
            listss.push_back(queries[i].second);
            freq[queries[i].second]++;
        }
        else if (!freq.empty())
        {
            int maxi = INT_MIN;
            for (auto it : freq)
            {
                maxi = max(maxi, it.second);
            }
            for (int k = listss.size() - 1; k >= 0; k++)
            {
                if (freq.find(listss[k] == maxi))
                {
                    removed.push_back(listss[k]);
                    freq[listss[k]]--;
                }
                listss.erase(k);
            }
        }
    }

    return removed;
}

int main()
{
    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
        string s;
        cin >> s;
        int n1 = 0;
        int n2 = 0;
        sort(s.begin(), s.end());
        int i = 0;
        while (i < s.size())
        {
            if (i % 2 == 0)
            {
                n1 = n1 * 10 + s[i] - '0';
            }
            else
            {
                n2 = n2 * 10 + s[i] - '0';
            }
            i++;
        }
        cout << n1 + n2 << endl;
    }
    return 0;
}