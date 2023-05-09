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
ll n, m, s, t;
bool visited[1000001];
vector<ll> adj[1000001];
void dfs(ll u)
{
    visited[u] = true;
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
    ll T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> s >> t;
        for (ll i = 1; i <= m; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        ll cnt = 0;
        for (ll i = 1; i <= n; i++)
        {
            visited[i] = true;
            dfs(s);
            if (visited[t] == false)
                cnt++;
            ms(visited);
        }
        cout << cnt << endl;
        for (auto &x : adj)
            x.clear();
        ms(visited);
    }
}