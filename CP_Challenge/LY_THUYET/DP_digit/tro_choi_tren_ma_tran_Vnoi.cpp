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
ll m = 8, n, f[10006][(1 << 8)], a[10006][8], d[(1 << 8) + 9], sum = _oo;
int main()
{
    faster();
    ll res = _oo;
    cin >> n;
    for (ll j = 0; j < 8; j++)
    {
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i][j];
            res = max(res, a[i][j]);
        }
    }
    if (res < 0)
        cout << res << endl;
    else
    {
        for (ll i = 0; i < (1 << 8); i++)
        {
            d[i] = 1;
            for (ll j = 0; j < 7; j++)
            {
                ll k = j + 1;
                if (bit(i, j) && bit(i, k))
                {
                    d[i] = 0;
                    break;
                }
            }
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll x = 0; x < (1 << 8); x++)
            {
                f[i][x] = _oo;
                if (d[x])
                {
                    if (i == 0)
                    {
                        ll ans = 0;
                        for (ll k = 0; k < 8; k++)
                        {
                            if (bit(x, k))
                                ans += a[i][k];
                        }
                        f[i][x] = ans;
                    }
                    else
                    {
                        ll ans = 0;
                        for (ll k = 0; k < 8; k++)
                        {
                            if (bit(x, k))
                                ans += a[i][k];
                        }
                        f[i][x] = ans;
                        for (ll j = 0; j < (1 << 8); j++)
                        {
                            if (d[j])
                            {
                                if ((x & j) == 0)
                                    f[i][x] = max(f[i][x], f[i - 1][j] + ans);
                            }
                        }
                    }
                }
                sum = max(sum, f[i][x]);
            }
        }
        cout << sum << endl;
    }
}