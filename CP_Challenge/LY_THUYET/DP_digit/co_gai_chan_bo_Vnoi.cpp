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
ll f[31][32] = {0}, n, m;
bool check(ll mask1, ll mask2)
{
    for (ll i = 0; i < m - 1; i++)
    {
        ll ans = 0;
        ll j = i + 1;
        ans += (bit(mask1, i)) + (bit(mask1, j));
        ans += (bit(mask2, i)) + (bit(mask2, j));
        if (ans % 4 == 0)
            return 0;
    }
    return 1;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        if (m > n)
            swap(n, m);
        for (ll x = 0; x < (1 << m); x++)
            f[0][x] = 1;
        for (ll i = 1; i < n; i++) // row
        {
            for (ll x = 0; x < (1 << m); x++) // mask1
            {
                f[i][x] = 0;
                for (ll j = 0; j < (1 << m); j++)
                {
                    if (check(x, j))
                        f[i][x] += f[i - 1][j];
                }
            }
        }
        ll ans = 0;
        for (ll i = 0; i < (1 << m); i++)
            ans += f[n - 1][i];
        cout << ans << endl;
        ms(f);
    }
}