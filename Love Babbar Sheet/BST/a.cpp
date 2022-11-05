#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<string, ll> msl;
typedef map<char, ll> mcl;
typedef map<string, string> mss;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define pf push_front
#define pob pop_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repr(i, n, b) for (ll i = n; i > b; i--)
#define repv(v) for (auto i : v)
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof a)
#define w(t)  \
    ll t;     \
    cin >> t; \
    while (t--)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define sz(v) ll(v.size())

const int N = 1e5 + 2;
const int mod = 1000000007;

ll power(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    ll ans = power(a, b / 2);
    ans *= ans;
    ans %= mod;
    if (b % 2)
    {
        ans *= a;
    }
    return ans % mod;
}

int main()
{
    FAST;
#ifndef ONLINE_JUDGE
    freopen("Output.txt", "w", stdout);
#endif
    // your code goes here
    ll tt = 1;
    w(t)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n], b[n];
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        bool ok = 1;
        ll j = n - 1;
        stack<ll> st;
        ll cnt = 0;
        rep(i, 0, n)
        {
            st.push(a[i]);
            if (a[i] != b[j])
            {
                continue;
            }
            bool ch = 0;
            while (!st.empty() && st.top() == b[j])
            {
                st.pop();
                ch = 1;
                j--;
            }
            if (ch)
                cnt++;
            if (!st.empty() || cnt > (k + 1))
            {
                ok = 0;
                break;
            }
        }
        cout << "Case #" << tt << ": ";
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        tt++;
    }
    return 0;
}