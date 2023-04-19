#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

vector<ll> adj[100001];
ll n, m, visited[1000001] = {0}, disc[1000001], low[1000001], timer = 0;
vector<pair<ll, ll>> edge;

bool ap[1000001];
void init_vh()
{
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (ll i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
    }
}

void dfs(ll u, ll par)
{
    low[u] = disc[u] = ++timer;
    int dem = 0; // dem xem dinh u co bn con
    for (auto v : adj[u])
    {
        if (v == par)
        {
            continue;
        }
        if (disc[v] == 0)
        {
            ++dem;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= disc[u] && par != -1)
            {
                ap[u] = true;
            }
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (par == -1 && dem > 1)
        ap[u] = true;
}

void dfs1(ll u, ll par)
{
    low[u] = disc[u] = ++timer;
    for (auto v : adj[u])
    {
        if (v == par)
        {
            continue;
        }
        if (disc[v] == 0)
        {
            dfs1(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
            {
                edge.push_back({u, v});
            }
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (disc[i] == 0)
        {
            dfs(i, -1);
        }
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ap[i])
        {
            cnt++;
        }
    }
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    timer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (disc[i] == 0)
        {
            dfs1(i, -1);
        }
    }
    cout << cnt << " " << edge.size() << endl;
}

int main()
{
    init_vh();
    solve();
}