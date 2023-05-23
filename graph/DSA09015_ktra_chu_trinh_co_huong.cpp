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
ll n, m;
vector<ll> adj[1000001];
bool visited[1000001];
bool dfs(ll u, ll parent)
{
    visited[u] = true;
    for (auto &x : adj[u])
    {
        if (!visited[x])
        {
            if (dfs(x, u))
                return true;
        }
        else if (x != parent)
            return true;
    }
    return false;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (ll i = 1; i <= m; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool ok = true;
        for (ll i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            cout << "NO" << endl;
            continue;
        }
        for (ll i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1))
                {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        ms(visited);
        for (auto &x : adj)
            x.clear();
    }
}