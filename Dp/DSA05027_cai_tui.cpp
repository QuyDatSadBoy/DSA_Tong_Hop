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

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, v;
        cin >> n >> v;
        ll c[n + 1], w[n + 1];
        for (ll i = 1; i <= n; i++)
            cin >> w[i];
        for (ll i = 1; i <= n; i++)
            cin >> c[i];
        ll f[n + 1][v + 1];
        ms(f);
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 0; j <= v; j++)
            {
                f[i][j] = f[i - 1][j];
                if (j >= w[i])
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + c[i]);
                }
            }
        }
        cout << f[n][v] << endl;
    }
}