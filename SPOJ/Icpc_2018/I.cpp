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
ll lcm(ll x, ll y)
{
    return x / __gcd(x, y) * y;
}
ll pow_mod(ll x, ll n)
{
    if (n == 0)
        return 1;
    ll res = pow_mod(x, n / 2);
    res *= res;
    if (n % 2 == 1)
        res *= x;
    return res;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y, z, n;
        cin >> x >> y >> z >> n;
        ll tam = lcm(z, lcm(x, y));
        ll left = (ll)(pow_mod(10, n - 1));
        ll right = (ll)(pow_mod(10, n) - 1);
        ll res = (left + tam - 1) / tam * tam;
        if (res >= left && res <= right)
            cout << res << endl;
        else
            cout << -1 << endl;
    }
}