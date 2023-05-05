#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll mul(ll a, ll b, ll mod)
{
    ll ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans % mod) + (a % mod) % mod;
        }
        a = (a % mod) + (a % mod) % mod;
        b /= 2;
    }
    return ans;
}
ll pow_mod(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans % mod) * (a % mod) % mod;
        }
        a = (a % mod) * (a % mod) % mod;
        b /= 2;
    }
    return ans;
}
bool check(ll d, ll n)
{
    ll a = rand() % (n - 3) + 2;
    ll x = pow_mod(a, d, n);
    if (x == 1 || x == n - 1)
        return 1;
    while (d != n - 1)
    {
        x = mul(x, x, n);
        d *= 2;
        if (x == n - 1)
            return 1;
    }
    return 0;
}
bool miler(ll n)
{
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    if (n < 5)
        return 0;
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (ll i = 1; i < 10; i++)
    {
        if (check(d, n) == 0)
            return 0;
    }
    return 1;
}
bool nto(ll n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    ll m = -1;
    while (m * m <= n)
    {
        m += 6;
        if (n % m == 0 || n % (m + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    faster();
    // 2 ^ p-1 ko dong du 1 mod p thi chac chan p ko la so nguyen to
    cout << nto(11) << endl;
}