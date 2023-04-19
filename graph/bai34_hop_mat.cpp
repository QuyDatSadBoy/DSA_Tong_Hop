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
ll k, n, m, visited[1000001] = {0};
vector<ll> adj[1000001];
map<ll, ll> mp;
void dfs(ll u)
{
    visited[u] = true;
    mp[u]++;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
}
int main()
{
    faster();
    cin >> k >> n >> m;
    ll a[k];
    for (auto &x : a)
        cin >> x;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (auto &x : a)
    {
        dfs(x);
        ms(visited);
    }
    ll cnt = 0;
    for (auto x : mp)
    {
        if (x.second == k)
            cnt++;
    }
    cout << cnt << endl;
}