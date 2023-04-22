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
ll n, m, visited[1000001] = {0}, parent[1000001] = {0};

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
void init_ch()
{
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (ll i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
    }
}
bool dfs(ll u)
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            parent[x] = u;
            if (!dfs(x))
            {
                return false;
            }
        }
        else
        {
            if (x != parent[u])
                return false;
        }
    }
    return true;
}
bool bfs(ll u)
{
    queue<ll> qe;
    qe.push(u);
    visited[u] = true;
    while (!qe.empty())
    {
        int top = qe.front();
        qe.pop();
        for (ll x : adj[top])
        {
            if (!visited[x])
            {
                visited[x] = true;
                qe.push(x);
                parent[x] = top;
            }
            else if (parent[top] != x)
                return false;
        }
    }
    return true;
}
void solve()
{
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (!bfs(i))
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        init_vh();
        solve();
        for (auto &x : adj)
        {
            x.clear();
        }
        ms(visited);
    }
}