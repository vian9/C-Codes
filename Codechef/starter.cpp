#include <iostream>
using namespace std;
#define ll long long int

int main()
{

    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll m, ll p;
    }
    return 0;
}

int main()
{

    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll m;
        ll p[m], c[m];
        for (int j = 0; j < m; j++)
        {
            cin >> p[i] >> c[i];
        }
        ll sellVal, total;
        cin >> total >> sellVal;
        ll cost = 0;
        for (int j = 0; j < m; j++)
        {
            cost += (p[i] * c[i]);
        }
        ll sell = sellVal * total;
        if (sell > cost)
        {
            cout << ((sell - cost) / cost) * 100 << endl;
        }
        else
        {
            cout << ((cost - sell) / cost) * 100 << endl;
        }
    }
    return 0;
}