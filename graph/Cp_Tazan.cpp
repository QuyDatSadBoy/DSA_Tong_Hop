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
ll n, m, disc[1000006], low[1000006], node = 0, edge = 0, timer = 0;
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
void Tazan(ll u, ll parent)
{
    low[u] = disc[u] = ++timer;
    ll dem = (parent != -1);
    for (auto x : adj[u])
    {
        if (x == parent)
            continue;
        if (disc[x] == 0)
        {
            Tazan(x, u);
            low[u] = min(low[u], low[x]);
            if (low[x] >= disc[u])
                dem++;
            if (low[x] == disc[x])
                edge++;
        }
        else
            low[u] = min(low[u], disc[x]);
    }
    if (dem >= 2)
        node++;
}
int main()
{
    faster();
    init();
    for (ll i = 1; i <= n; i++)
    {
        if (!disc[i])
        {
            Tazan(i, -1);
        }
    }
    cout << edge << endl;
}