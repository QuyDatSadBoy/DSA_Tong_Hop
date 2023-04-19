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
    for (auto v : adj[u])
    {
        if (v == par)
        {
            continue;
        }
        if (disc[v] == 0)
        {
            dfs(v, u);
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
    cout << edge.size() << endl;
}
int main()
{
    faster();
    init_vh();
    solve();
}