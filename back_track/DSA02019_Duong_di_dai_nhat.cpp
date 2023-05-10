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
ll n, m, ans;
vector<ll> adj[21];
bool visited[21][21];
void dfs(ll u, ll cnt)
{
    ans = max(ans, cnt);
    for (auto x : adj[u])
    {
        if (!visited[x][u])
        {
            visited[x][u] = visited[u][x] = true;
            dfs(x, cnt + 1);
            visited[x][u] = visited[u][x] = false;
        }
    }
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (ll i = 0; i < n; i++)
        {
            dfs(i, 0);
        }
        cout << ans << endl;
        ans = 0;
        for (auto &x : adj)
            x.clear();
        ms(visited);
    }
}