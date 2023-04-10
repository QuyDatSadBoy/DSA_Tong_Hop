#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll n, k;
struct matrix
{
    ll a[11][11];
    friend istream &operator>>(istream &in, matrix &x)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                in >> x.a[i][j];
            }
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, matrix x)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                out << x.a[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
    matrix operator*(matrix x)
    {
        matrix res;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                res.a[i][j] = 0;
                for (ll k = 0; k < n; k++)
                {
                    res.a[i][j] = res.a[i][j] % mod + (a[i][k] % mod) * (x.a[k][j] % mod) % mod;
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};
matrix pow_mod(matrix a, ll n)
{
    if (n == 1)
        return a;
    matrix res = pow_mod(a, n / 2);
    if (n % 2 == 0)
    {
        return res * res;
    }
    else
        return res * res * a;
}
int main()
{
    faster();
    cin >> n >> k;
    matrix a;
    cin >> a;
    matrix res = pow_mod(a, k);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += res.a[i][n - 1];
        ans %= mod;
    }
    cout << ans << endl;
}