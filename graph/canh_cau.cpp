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
ll n, m, visited[1000001] = {0};
vector<pair<ll, ll>> edge;

void init_vh()
{
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edge.push_back({x, y});
    }
    for (ll i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
    }
}
void init_ch()
{
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}
void dfs(ll u, ll s, ll t)
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if ((u == s && x == t) || (u == t && x == s))
        {
            continue;
        }
        if (!visited[x])
        {
            dfs(x, s, t);
        }
    }
}
void bfs(ll u)
{
    queue<ll> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        for (auto y : adj[x])
        {
            if (!visited[y])
            {
                visited[y] = true;
                q.push(y);
            }
        }
    }
}
void solve()
{
    ll cnt = 0, ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i, 0, 0);
        }
    }
    ms(visited);
    for (auto x : edge)
    {
        ll s = x.first, t = x.second;
        ll dem = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dem++;
                dfs(i, s, t);
            }
        }
        if (dem > cnt)
            ans++;
        ms(visited);
    }
    cout << ans << endl;
}
int main()
{
    faster();
    init_vh();
    solve();
}