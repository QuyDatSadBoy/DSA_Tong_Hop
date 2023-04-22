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
ll n, m, s, a[1001][1001];
vector<pair<ll, ll>> adj[1000001];

void nhap()
{
    cin >> n >> s;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (j > i && a[i][j] != 0 && a[i][j] != 1e9)
            {
                adj[i].push_back({j, a[i][j]});
                adj[j].push_back({i, a[i][j]});
            }
        }
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