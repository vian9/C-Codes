#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll qx;
    cin >> qx;
    for (ll t = 0; t < qx; t++)
    {
        ll x, y;
        cin >> x >> y;
        ll count = 0;
        if (y > x)
        {
            swap(x, y);
        }

        if (x == y && x != 0)
        {
            cout << x << endl;
        }
        else if (x == 0 || y == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            while (y <= x)
            {
                count++;
                y = 2 * y;
            }
            y = y / 2;

            if (y == x)
            {
                cout << x + count - 1 << endl;
            }
            else
            {
                cout << x + count << endl;
            }
        }
    }
    return 0;
}