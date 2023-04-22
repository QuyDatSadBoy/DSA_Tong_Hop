#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll n, m, s;
vector<pair<ll, ll>> adj[1000001];

void nhap()
{
    cin >> n >> m >> s;
    for (ll i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}
void dijkstra(ll s)
{
    ll d[n + 1] = {0};
    for (ll i = 1; i <= n; i++)
        d[i] = (int)1e9;
    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> qe;
    qe.push({0, s});
    while (!qe.empty())
    {
        auto top = qe.top();
        qe.pop();
        int kc = top.first, dinh = top.second;
        if (kc > d[dinh])
            continue;
        for (auto it : adj[dinh])
        {
            int w = it.second;
            int u = it.first;
            if (d[u] > d[dinh] + w)
            {
                d[u] = d[dinh] + w;
                qe.push({d[u], u});
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
        nhap();
        dijkstra(s);
        for (auto &x : adj)
            x.clear();
    }
}