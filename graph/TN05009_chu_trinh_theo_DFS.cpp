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
ll n, m, en, cha[1000001];
vector<ll> adj[1000001];
bool visited[1000001];
bool dfs(ll u, ll parent)
{
    visited[u] = true;
    for (auto &x : adj[u])
    {
        if (!visited[x])
        {
            cha[x] = u;
            if (dfs(x, u))
                return true;
        }
        else if (x != parent)
        {
            en = u;
            return true;
        }
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
        for (ll i = 1; i <= n; i++)
        {
            sort(all(adj[i]));
            cha[i] = i;
        }
        bool ok = false;
        if (dfs(1, -1))
            ok = true;
        if (!ok)
            cout << "NO" << endl;
        else
        {
            vector<ll> path;
            path.push_back(en);
            while (en != cha[en])
            {
                en = cha[en];
                path.push_back(en);
            }
            reverse(all(path));
            for (auto x : path)
                cout << x << " ";
            cout << en << " ";
            cout << endl;
        }
        ms(visited);
        for (auto &x : adj)
            x.clear();
        ms(cha);
    }
}