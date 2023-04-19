#include <bits/stdc++.h>
#define ll long long
// #pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll f[100001][101], res = 0;
int main()
{
    // faster();
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (auto &x : a)
        cin >> x;
    ms(f);
    if (!a[0])
    {
        for (ll i = 1; i <= m; i++)
        {
            f[0][i] = 1;
        }
    }
    else
        f[0][a[0]] = 1;
    for (ll i = 1; i < n; i++)
    {
        if (!a[i])
        {
            for (ll j = 1; j <= m; j++)
            {
                for (ll k = -1; k <= 1; k++)
                {
                    ll ans = k + j;
                    if (ans >= 1 && ans <= m)
                    {
                        f[i][j] += f[i - 1][ans];
                        f[i][j] %= mod;
                    }
                }
            }
        }
        else
        {
            for (ll k = -1; k <= 1; k++)
            {
                ll ans = k + a[i];
                if (ans >= 1 && ans <= m)
                {
                    f[i][a[i]] += f[i - 1][ans];
                    f[i][a[i]] %= mod;
                }
            }
        }
    }
    for (ll i = 1; i <= m; i++)
    {
        res += f[n - 1][i];
        res %= mod;
    }
    cout << res << endl;
}