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
ll n, m, s, t, visited[1000001] = {0};
int parent[1000001]; // lưu cha của đỉnh u

void init_vh()
{
    cin >> n >> m >> s >> t;
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
void dfs(ll u)
{
    visited[u] = true;
    cout << u << " ";
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            dfs(x);
            parent[x] = u;
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
        cout << x << " ";
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
    dfs(s);
    cout << endl;
    if (visited[t])
    {
        vector<ll> way;
        way.push_back(t);
        while (s != t)
        {
            t = parent[t];
            way.push_back(t);
        }
        reverse(all(way));
        cout << "Đường đi từ s đến t là :" << endl;
        for (auto x : way)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    ms(visited);
    ms(parent);
    for (auto x : adj)
    {
        x.clear();
    }
}
int main()
{
    faster();
    init_vh();
    solve();
}