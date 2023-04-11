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
vector<ll> adj[1000001];
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
        edges.push_back({x, y, w});
    }
}
bool check()
{
    for (ll i = 1; i <= n; i++)
    {
        if (visited[i] == false)
            return false;
    }
    return true;
}
void prim(ll s)
{
    visited[s] = true;
    sort(all(edges), cmp);
    ll d = 0, cnt = 0;
    while (!check())
    {
        for (ll i = 0; i < m; i++)
        {
            int x = edges[i].x, y = edges[i].y, w = edges[i].w;
            if (visited[x] != visited[y])
            {
                d += w;
                visited[x] = visited[y] = true;
                cnt++;
                break;
            }
        }
    }
    if (cnt != n - 1)
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