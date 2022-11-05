#include <iostream>
#include <math.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll p;
        cin >> p;
        ll arr[p];
        for (ll j = 0; j < p; j++)
        {
            cin >> arr[j];
        }

        ll countt = 0, counto = 0, counttty = 0;
        for (ll j = 0; j < p; j++)
        {
            if (arr[j] == 1)
            {
                countt++;
            }
            else if (arr[j] == 2)
            {
                counto++;
            }
            else if (arr[j] > 1)
            {
                counttty++;
            }
        }
        ll a = countt * (p - countt);
        if (countt > 1)
        {
            a += ((countt * (countt - 1)) / 2);
        }
        if (counto > 1)
        {
            a += ((counto * (counto - 1)) / 2);
        }

        cout << a << endl;
    }

    return 0;
}