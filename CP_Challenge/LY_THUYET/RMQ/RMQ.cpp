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
ll n, q, a[maxn], mi[21][maxn];
ll get(ll l, ll r)
{
    ll k = log2(r - l + 1);
    return min(mi[k][l], mi[k][r - (1 << k) + 1]);
}
int main()
{
    faster();
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mi[0][i] = a[i];
    }
    for (ll l = 1; (1 << l) <= n; ++l)
    {
        for (ll i = 1; i + (1 << l) - 1 <= n; ++i)
        {
            mi[l][i] = min(mi[l - 1][i], mi[l - 1][i + (1 << (l - 1))]);
        }
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << get(l, r) << endl;
    }
}