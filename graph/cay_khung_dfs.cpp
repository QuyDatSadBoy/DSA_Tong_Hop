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
ll n, m, u, visited[1000001];
vector<ll> adj[1000001];
vector<string> res;
void init()
{
    cin >> n >> m >> u;
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
void dfs(ll u)
{
    visited[u] = 1;
    for (auto &x : adj[u])
    {
        if (!visited[x])
        {
            string s = "";
            s = to_string(u) + "->" + to_string(x);
            res.push_back(s);
            dfs(x);
        }
    }
}
int main()
{
    faster();
    init();
    dfs(u);
    for (auto &x : res)
    {
        cout << x << endl;
    }
}