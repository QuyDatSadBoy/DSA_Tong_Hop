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
vector<ll> adj[1001];
ll disc[1001], low[1001], timer = 0;
set<pair<ll, ll>> se;
void Tazan(ll u, ll parent)
{
    disc[u] = low[u] = ++timer;
    for (auto &x : adj[u])
    {
        if (x == parent)
            continue;
        if (disc[x] == 0)
        {
            Tazan(x, u);
            low[u] = min(low[u], low[x]);
            if (low[x] == disc[x])
            {
                se.insert({min(x, u), max(x, u)});
            }
        }
        else
            low[u] = min(low[u], disc[x]);
    }
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
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
            if (disc[i] == 0)
            {
                Tazan(i, -1);
            }
        }
        if (se.size())
        {
            for (auto x : se)
            {
                cout << x.first << " " << x.second << " ";
            }
            cout << endl;
        }
        else
            cout << 0 << endl;
        se.clear();
        ms(disc);
        ms(low);
        timer = 0;
        for (auto &x : adj)
            x.clear();
    }
}