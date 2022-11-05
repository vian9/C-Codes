#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll q;
    cin >> q;
    vector<ll> two;
    two.push_back(1);
    ll mo = 1000000007;
    for (int i = 0; i < 1000000; i++)
    {
        ll size = two.size();
        ll p = two[size - 1] * 2;
        two.push_back(p % mo);
    }

    for (ll t = 0; t < q; t++)
    {
        ll n, x;
        cin >> n >> x;
        ll value = two[n - 1] * x;
        cout << value % mo << endl;
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
        ll x1, y1;
        cin >> x1 >> y1;
        ll x2, y2;
        cin >> x2 >> y2;
        if ((abs(x1 - x2) == 0 && abs(y1 - y2) == 2))
        {
            cout << "YES" << endl;
        }
        else if ((abs(x1 - x2) == 2 && abs(y1 - y2) == 0))
        {
            cout << "YES" << endl;
        }
        else if ((abs(x1 - x2) == 0 && abs(y1 - y2) == 4))
        {
            cout << "YES" << endl;
        }
        else if ((abs(x1 - x2) == 4 && abs(y1 - y2) == 0))
        {
            cout << "YES" << endl;
        }
        else if ((abs(x1 - x2) == 1 && abs(y1 - y2) == 3))
        {
            cout << "YES" << endl;
        }
        else if ((abs(x1 - x2) == 3 && abs(y1 - y2) == 1))
        {
            cout << "YES" << endl;
        }
        else if ((abs(x1 - x2) == 3 && abs(y1 - y2) == 3))
        {
            cout << "YES" << endl;
        }
        else if ((abs(x1 - x2) == 2 && abs(y1 - y2) == 4))
        {
            cout << "YES" << endl;
        }
        else if ((abs(x1 - x2) == 4 && abs(y1 - y2) == 2))
        {
            cout << "YES" << endl;
        }
        else if ((abs(x1 - x2) == 1 && abs(y1 - y2) == 1))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
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
        ll n, k;
        cin >> n >> k;
        ll i = n;
        ll ans = 1;
        while (i > 0)
        {
            ans = ans * 4;
            i--;
        }
        ans -= ((1 << n) - 1) * 3;
        cout << ans - 1 << endl;
    }
    return 0;
}