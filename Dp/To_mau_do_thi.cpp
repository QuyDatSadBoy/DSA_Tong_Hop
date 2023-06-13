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
ll n, m, k;
vector<ll> adj[1000001];
ll color[1000001], a[1000001];
bool cmp(ll x, ll y)
{
    return adj[x].size() > adj[y].size();
}
bool check(ll u, ll c)
{
    for (auto &v : adj[u])
    {
        if (color[v] == c)
            return false;
    }
    return true;
}
void inp()
{
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
        a[i] = i + 1;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    sort(a, a + n, cmp);
}
void solve()
{
    inp();
    ll res = 0, cnt = 1;
    while (res < n)
    {
        for (ll i = 0; i < n; i++)
        {
            if (!color[a[i]] && check(a[i], cnt))
            {
                color[a[i]] = cnt;
                res++;
            }
        }
        if (res == n)
            break;
        cnt++;
    }
    if (cnt <= k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    ms(color);
    ms(a);
    for (auto &x : adj)
        x.clear();
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}