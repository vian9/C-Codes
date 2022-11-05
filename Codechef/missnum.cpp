/*Alice (uniformly and independently) randomly picks two integers a,b
 from the range [1,104]
, and writes down the values of a+b
, a−b
, a⋅b
 and ⌊ab⌋
(integer division) in some random order. Unfortunately, she forgot the values of a
and b
. You need to help her to find out if there exists two integers a,b
 such that 1≤a,b≤104
 and a+b
, a−b
, a⋅b
, ⌊ab⌋
 are the numbers she has written down.
IN:
 2
-1 72 0 17
1 4 5 6
OUT:
8 9
-1 -1
  */

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll arr[4];
        for (int i = 0; i < 4; i++)
            cin >> arr[i];

        // phle sort krdia bcoz we don't knw ordr.....nd nm tbhi exst krga jb s d se phle aaye otws wl goto -1 -1 as srtd.
        sort(arr, arr + 4);

        // wo 4 seq me se ek mtch krga jo ans dega..... s m a d, d s a m, s d a m, d s m a.
        ll a1 = (arr[2] + arr[0]) / 2;
        ll b1 = arr[2] - a1;
        ll a2 = (arr[2] + arr[1]) / 2;
        ll b2 = arr[2] - a2;
        ll a3 = (arr[3] + arr[0]) / 2;
        ll b3 = arr[3] - a3;
        ll a4 = (arr[3] + arr[1]) / 2;
        ll b4 = arr[3] - a4;

        // chck condn +ve nd not 0 ..... also 1 nd 10000 k beech m h
        if ((a1 % 1 == 0) && (a1 != 0) && (b1 % 1 == 0) && (b1 != 0))
            // sdam
            if ((a1 / b1 == arr[1]) && (a1 * b1 == arr[3]) && (a1 >= 1) && (b1 >= 1) && (a1 <= 10000) && (b1 <= 10000))
            {
                cout << a1 << " " << b1 << endl;
                continue;
            }
        if ((a2 % 1 == 0) && (a2 != 0) && (b2 % 1 == 0) && (b2 != 0))
            // dsam
            if ((a2 / b2 == arr[0]) && (a2 * b2 == arr[3]) && (a2 >= 1) && (b2 >= 1) && (a2 <= 10000) && (b2 <= 10000))
            {
                cout << a2 << " " << b2 << endl;
                continue;
            }
        if ((a3 % 1 == 0) && (a3 != 0) && (b3 % 1 == 0) && (b3 != 0))
            // sdma
            if ((a3 / b3 == arr[1]) && (a3 * b3 == arr[2]) && (a3 >= 1) && (b3 >= 1) && (a3 <= 10000) && (b3 <= 10000))
            {
                cout << a3 << " " << b3 << endl;
                continue;
            }
        if ((a4 % 1 == 0) && (a4 != 0) && (b4 % 1 == 0) && (b4 != 0))
            // dsma
            if ((a4 / b4 == arr[0]) && (a4 * b4 == arr[2]) && (a4 >= 1) && (b4 >= 1) && (a4 <= 10000) && (b4 <= 10000))
            {
                cout << a4 << " " << b4 << endl;
                continue;
            }
        cout << "-1 -1" << endl;
    }
    return 0;
}