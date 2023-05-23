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
ll a[10], f[101];
void init()
{
    for (ll i = 1; i <= 9; i++)
        a[i] = 1;
    f[1] = 10;
    for (ll i = 2; i <= 100; i++)
    {
        for (ll j = 1; j <= 9; j++)
        {
            ll s = 0;
            for (ll k = j; k <= 9; k++)
            {
                s += a[k];
            }
            a[j] = s;
            f[i] = ((f[i] % mod) + (s % mod)) % mod;
        }
    }
    for (ll i = 2; i <= 100; i++)
        f[i] = ((f[i] % mod) + (f[i - 1] % mod)) % mod;
}
int main()
{
    faster();
    init();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << f[n] << endl;
    }
}