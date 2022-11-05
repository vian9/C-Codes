#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
        ll m, n;
        cin >> n >> m;
        string a, b;
        cin >> a;
        cin >> b;
        ll ans1 = a[0];
        ll ans2 = b[0];
        for (int i = 1; i < a.length(); i++)
        {
            ans1 = (ans1 ^ a[i]);
        }
        for (int i = 1; i < b.length(); i++)
        {
            ans2 = (ans2 ^ b[i]);
        }
        if (ans1 == ans2)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;

        // if (n > m && (counta0 < countb0 || counta1 < countb1))
        // {
        //     cout << "NO" << endl;
        //     continue;
        // }

        // string s;
        // s.insert(a.begin() + n - m + 1, m - 1);
        // string p;
        // p.insert(b.begin() + 1, m - 1);

        // if (s.compare(p) == 0)
        //     cout << "YES" << endl;
        // else
        //     cout << "NO" << endl;
    }
    return 0;
}