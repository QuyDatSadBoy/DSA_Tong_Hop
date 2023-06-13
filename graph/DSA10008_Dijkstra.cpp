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
ll n, m, s;
vector<pair<ll, ll>> adj[1000001];
void dijkstra(ll s)
{
    ll d[n + 1] = {0};
    for (ll i = 1; i <= n; i++)
    {
        d[i] = 1e18;
    }
    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> qe;
    qe.push({0, s});
    while (qe.size())
    {
        auto top = qe.top();
        qe.pop();
        ll w = top.first;
        ll u = top.second;
        if (w > d[u])
            continue;
        for (auto v : adj[u])
        {
            ll dinh = v.first;
            ll w2 = v.second;
            if (d[dinh] > d[u] + w2)
            {
                d[dinh] = d[u] + w2;
                qe.push({d[dinh], dinh});
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> s;
        for (ll i = 1; i <= m; i++)
        {
            ll x, y, w;
            cin >> x >> y >> w;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        dijkstra(s);
        for (auto &x : adj)
            x.clear();
    }
}