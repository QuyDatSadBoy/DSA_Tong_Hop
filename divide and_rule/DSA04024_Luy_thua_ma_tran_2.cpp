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
ll n, r;
struct matrix
{
    ll a[15][15];
    matrix operator*(matrix b)
    {
        matrix res;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                res.a[i][j] = 0;
                for (ll k = 0; k < n; k++)
                {
                    ll tam = ((a[i][k] % mod) * (b.a[k][j] % mod)) % mod;
                    res.a[i][j] = ((res.a[i][j] % mod) + (tam % mod)) % mod;
                }
            }
        }
        return res;
    }
};
matrix pow_mod(matrix b, ll k)
{
    if (k == 1)
        return b;
    matrix res = pow_mod(b, k / 2);
    res = res * res;
    if (k % 2 == 1)
        res = (res * b);
    return res;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> r;
        matrix b;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> b.a[i][j];
            }
        }
        ll ans = 0;
        matrix res = pow_mod(b, r);
        for (ll i = 0; i < n; i++)
        {
            ans = ((ans % mod) + (res.a[i][n - 1] % mod)) % mod;
        }
        cout << ans << endl;
    }
}