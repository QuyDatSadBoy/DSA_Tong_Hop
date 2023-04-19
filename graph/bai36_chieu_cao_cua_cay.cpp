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
ll n;
vector<ll> adj[1000001], path(1000001, 0);
bool visited[1000001];
void init()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void dfs(ll u, ll cnt)
{
    path[u] = cnt;
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            dfs(x, cnt + 1);
        }
    }
}
int main()
{
    faster();
    init();
    dfs(1, 0);
    for (ll i = 1; i <= n; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}