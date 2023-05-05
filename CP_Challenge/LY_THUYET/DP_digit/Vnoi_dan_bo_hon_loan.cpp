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
ll n, k, f[17][(1 << 17)], a[17], ans = 0;
int main()
{
    faster();
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        f[i][(1 << i)] = 1;
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
                        if (abs(a[i] - a[j]) > k)
                        {
                            f[i][x] += f[j][pre];
                        }
                    }
                }
            }
        }
    }
    for (ll i = 0; i < n; i++)
        ans += f[i][(1 << n) - 1];
    cout << ans << endl;
}