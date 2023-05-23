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
ll f[1001];
void init()
{
    f[0] = 1;
    for (ll i = 1; i <= 1000; i++)
    {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }
}
ll pow_mod(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll res = pow_mod(a, b / 2, mod) % mod;
    res = (res * res) % mod;
    if (b & 1)
        res = (res * a) % mod;
    return res;
}
ll inverse(ll a, ll b)
{
    return pow_mod(a, b - 2, b);
}
int main()
{
    faster();
    init();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        if (m > n)
            cout << 0 << endl;
        else
        {
            ll res = inverse(f[n - m], mod) % mod;
            res = res * (f[n]) % mod;
            cout << res << endl;
        }
    }
}