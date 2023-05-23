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
        ll n, s;
        cin >> n >> s;
        ll a[n + 1], res = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ll f[s + 1] = {0};
        f[0] = 1;
        for (ll k = 1; k <= s; k++)
        {
            for (ll i = 1; i <= n; i++)
            {
                if (k >= a[i])
                {
                    f[k] += f[k - a[i]];
                    f[k] %= mod;
                }
            }
        }
        cout << f[s] << endl;
    }
}