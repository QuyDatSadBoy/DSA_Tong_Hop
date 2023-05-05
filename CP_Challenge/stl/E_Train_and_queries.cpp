#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        ll a[n + 1];
        map<ll, ll> f, s;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (f[a[i]] == 0)
                f[a[i]] = i;
            s[a[i]] = i;
        }
        while (q--)
        {
            ll x, y;
            cin >> x >> y;
            if (f[x] <= s[y] && f[x])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}