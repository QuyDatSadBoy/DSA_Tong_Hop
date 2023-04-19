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
ll n, m, a[1000001], visited[1000001], res = 0;
vector<ll> adj[1000001];
void init()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void dfs(ll u, ll dem)
{
    visited[u] = true;
    if (dem > m)
    {
        return;
    }
    if (adj[u].size() == 1 && u != 1)
        res++;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            if (a[x])
            {
                dfs(x, dem + 1);
            }
            else
                dfs(x, 0);
        }
    }
}
int main()
{
    faster();
    init();
    dfs(1, a[1]);
    cout << res << endl;
    return 0;
}