#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)(1e9 + 7);
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll f[1252510] = {0};
ll pow_mod(ll a, ll b, ll m)
{
    if (b == 0)
    {
        return 1;
    }
    ll tam = pow_mod(a, b / 2, m);
    if (b & 1)
        return (tam % m) * (tam % m) % m * (a % m) % m;
    else
        return (tam % m) * (tam % m) % m;
}
ll inverse(ll a)
{
    return pow_mod(a, mod - 2, mod);
}
int main()
{
    faster();
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    if (sum % 2 != 0)
        cout << 0 << endl;
    else
    {
        ms(f);
        sum /= 2;
        f[0] = 1;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = sum; j >= 1; j--)
            {
                if (j >= i)
                {
                    f[j] = f[j] % mod + (f[j - i] % mod) % mod;
                }
            }
        }
    }
    cout << (f[sum] % mod) * (inverse(2) % mod) % mod << endl;
}