#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define maxn 1000006
#define _oo LLONG_MIN
#define oo LLONG_MAX - 9
#define bit(x, i) (x & (1 << i))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll f[16][(1 << 15)], n, c[17][17];
int main()
{
    faster();
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
            cin >> c[i][j];
    }
    ll ans = oo;
    for (ll x = 0; x < (1 << n); x++)
        for (ll i = 0; i < n; i++)
            f[i][x] = oo;
    for (ll i = 0; i < n; i++)
    {
        f[i][1 << i] = 0;
    }
    for (ll x = 0; x < (1 << n); x++)
    {
        for (ll i = 0; i < n; i++)
        {
            if (bit(x, i))
            {
                ll pre = x - (1 << i);
                for (ll j = 0; j < n; j++)
                {
                    if (bit(pre, j))
                    {
                        f[i][x] = min(f[i][x], f[j][pre] + c[j][i]);
                    }
                }
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        ans = min(ans, f[i][(1 << n) - 1]);
    }
    cout << ans << endl;
}