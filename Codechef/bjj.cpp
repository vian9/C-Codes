#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll check(map<ll, vector<ll>> &edges, ll sv, ll ev, vector<ll> &av, vector<ll> &end, vector<ll> &middle)
{
    ll counts = av[sv];
    ll total = 0;
    for (auto &i : edges[sv])
    {
        if (i != ev)
        {
            ll current = check(edges, i, sv, av, end, middle);
            total += current;
            counts = __gcd(counts, current);
        }
    }
    middle[sv] = counts;
    end[sv] = total;
    return counts;
}

void search(ll sv, ll ev, ll su, map<ll, vector<ll>> &edges, vector<ll> &av, vector<ll> &end, vector<ll> &middle, ll &count)
{
    count = max(count, su);
    for (auto &i : edges[sv])
    {
        if (i != ev)
        {
            search(i, sv, su + end[i] - middle[i], edges, av, end, middle, count);
        }
    }
}

int main()
{
    ll qx;
    cin >> qx;
    for (ll t = 0; t < qx; t++)
    {
        ll n;
        cin >> n;
        vector<ll> av(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> av[i];
        }
        map<ll, vector<ll>> edges;
        for (ll i = 0; i < n - 1; i++)
        {
            ll f, s;
            cin >> f >> s;
            edges[f - 1].push_back(s - 1);
            edges[s - 1].push_back(f - 1);
        }
        vector<ll> middle(n);
        vector<ll> end(n);
        ll count = 0;
        ll current = -1;
        ll value = check(edges, 0, current, av, end, middle);
        search(0, current, end[0], edges, av, end, middle, count);
        cout << count << endl;
    }
    return 0;
}