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
ll n, a[maxn], node[maxn * 4 + 1], q;
ll get_max(ll id, ll l, ll r, ll u, ll v)
{
    if (r < u || v < l)
        return LLONG_MIN;
    if (u <= l && r <= v)
        return node[id];
    ll m = (l + r) / 2;
    ll max_L = get_max(id * 2, l, m, u, v);
    ll max_R = get_max(id * 2 + 1, m + 1, r, u, v);
    return max(max_L, max_R);
}
void update(ll id, ll l, ll r, ll pos, ll val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        a[l] = val;
        node[id] = val;
        return;
    }
    ll m = (l + r) / 2;
    update(id * 2, l, m, pos, val);
    update(id * 2 + 1, m + 1, r, pos, val);
    node[id] = max(node[id * 2], node[id * 2 + 1]);
}
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        node[id] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    node[id] = max(node[id * 2], node[id * 2 + 1]);
}
int main()
{
    faster();
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while (q--)
    {
        ll type, x, y;
        cin >> type >> x >> y;
        if (type == 1)
            update(1, 1, n, x, y);
        else
            cout << get_max(1, 1, n, x, y) << endl;
    }
}