// Link: https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
// Approach -> O(n+m) .... set lia and usme push krdia values jo distinct hai.....ab total set k size return krdia

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int

int doUnion(int a[], int n, int b[], int m)
{
    // using set
    set<int> item;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        item.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        item.insert(b[i]);
    }

    for (int i = 0; i < item.size(); i++)
    {
        total++;
    }
    return total;
}
int main()
{
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    ll a[n];
    ll b[m];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << doUnion(a, n, b, m) << endl;

    return 0;
}