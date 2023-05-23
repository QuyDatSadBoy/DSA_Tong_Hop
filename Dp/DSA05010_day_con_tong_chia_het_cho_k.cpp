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
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (auto &x : a)
            cin >> x;
        ll f[n][k];
        ms(f);
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < k; j++)
                f[i][j] = -1e9;
        }
        f[0][a[0] % k] = 1;
        for (ll i = 1; i < n; i++)
        {
            for (ll j = 0; j < k; j++)
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][(j - (a[i] % k) + k) % k] + 1);
            }
        }
        cout << f[n - 1][0] << endl;
    }
}