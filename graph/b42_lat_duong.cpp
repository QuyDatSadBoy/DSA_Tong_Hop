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
ll n, m, res = 1, parent[1000001], size[1000001];
void kt()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}
ll find(ll x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}
ll union_find(ll x, ll y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return 0;
    if (size[x] < size[y])
    {
        size[y] += size[x];
        parent[x] = y;
    }
    else
    {
        size[x] += size[y];
        parent[y] = x;
    }
    res = max({res, size[x], size[y]});
    return 1;
}
int main()
{
    faster();
    kt();
    ll ans = n;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        ans -= union_find(x, y);
        cout << ans << " " << res << endl;
    }
}