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
ll n, m, disc[1000001], low[1000001], timer = 0, ap[1000001];
vector<ll> adj[1000001];
void init()
{
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void tazan(ll u, ll par)
{
    disc[u] = low[u] = ++timer;
    ll dem = 0;
    for (auto x : adj[u])
    {
        if (!disc[x])
        {
            tazan(x, u);
            low[u] = min(low[u], low[x]);
            if (low[x] >= disc[u] && par != -1)
            {
                ap[u] = 1;
            }
        }
        else
            low[u] = min(low[u], disc[x]);
    }
    if (dem > 1 && par == -1)
    {
        ap[u] = 1;
    }
}
int main()
{
    faster();
    init();
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!disc[i])
        {
            tazan(i, -1);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (ap[i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}