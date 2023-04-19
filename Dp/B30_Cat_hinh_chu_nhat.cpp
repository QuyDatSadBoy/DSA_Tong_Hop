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
ll f[501][501];
int main()
{
    faster();
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            f[i][j] = 1e9;
        }
    }
    for (ll i = 1; i <= min(n, m); i++)
    {
        f[i][i] = 0;
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            for (ll k = 1; k < i; k++)
            {
                f[i][j] = min(f[i][j], f[k][j] + f[i - k][j] + 1);
            }
            for (ll k = 1; k < j; k++)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[i][j - k] + 1);
            }
        }
    }
    cout << f[n][m] << endl;
}