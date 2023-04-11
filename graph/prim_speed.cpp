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
ll n, m, visited[1000001], parent[1000001], size[1000001];
vector<pair<ll, ll>> adj[1000001];
// prim la giai thuat tham lam
struct edge
{
    ll x, y, w;
};
vector<edge> edges;
bool cmp(edge x, edge y) { return x.w < y.w; };
void init()
{
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void prim(ll s)
{
    ll d = 0, cnt = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> qe;
    qe.push({0, s});
    while (!qe.empty())
    {
        // lay ra thang o dau
        auto top = qe.top();
        qe.pop();
        if (visited[top.second])
            continue;
        d += top.first;
        cnt++;
        visited[top.second] = true;
        for (auto it : adj[top.second])
        {
            // it.first dinh ke voi top.second
            // it.second trong so
            if (!visited[it.first])
                qe.push({it.second, it.first});
        }
    }
    if (cnt != n)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << d << endl;
}

int main()
{
    faster();
    init();
    prim(1);
}