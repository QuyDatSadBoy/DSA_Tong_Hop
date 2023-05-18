#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define _oo LLONG_MIN
#define oo LLONG_MAX - 9
#define bit(x, i) ((x >> i) & 1)
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
bool check(ll pos, ll a[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        if (a[i] / pos == a[i] / (pos + 1))
            return 0;
    }
    return 1;
}
int main()
{
    faster();
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    ll res = 0;
    for (ll i = b[0]; i >= 0; i--)
    {
        if (check(i, a, n))
        {
            for (ll j = 0; j < n; j++)
            {
                res += a[j] / (i + 1) + 1;
            }
            break;
        }
    }
    cout << res << endl;
}