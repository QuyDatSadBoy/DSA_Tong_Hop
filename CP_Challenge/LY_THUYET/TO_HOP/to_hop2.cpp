#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
// Nếu p là số nto thì a^p -a chia hết cho p
//  a^-1 được goij là nghịch đảo modul của a nếu a*(a^-1) đồng dư với 1 mod p
long pow_mod(ll a, ll b)
{
    ll ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}
ll fact[1000001], inv[1000001];
int main()
{
    faster();
    fact[0] = 1;
    ll n, k;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv[n] = pow_mod(fact[n], mod - 2);
    for (ll i = n - 1; i >= 0; i--)
    {
        inv[i] = (i + 1) * inv[i + 1] % mod;
    }
    cout << fact[n] * inv[k] % mod * inv[n - k] % mod;
}