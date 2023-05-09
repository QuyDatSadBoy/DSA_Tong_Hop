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

struct edge
{
    ll x, y, w;
};
vector<edge> edges;
// Kruskal khong ap dung cho do thi co huong
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
    for (ll i = 1; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

// toi uu nen duong
ll find(ll u)
{
    if (u == parent[u])
        return u;
    else
        return parent[u] = find(parent[u]);
}
// union
bool Union(ll x, ll y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    if (size[x] < size[y])
    {
        size[y] += size[x];
        parent[x] = y;
    }
    else
    {
        parent[y] = x;
        size[x] += size[y];
    }
    return true;
}

void Kruskal()
{
    ll d = 0;
    vector<edge> Mst;
    sort(all(edges), cmp);
    for (ll i = 0; i < m; i++)
    {
        if (Mst.size() == n - 1)
            break;
        int x = edges[i].x, y = edges[i].y, w = edges[i].w;
        if (Union(x, y))
        {
            d += w;
            Mst.push_back({x, y, w});
        }
    }
    if (Mst.size() != n - 1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << d << endl;
    }
}
int main()
{
    faster();
    init();
    Kruskal();
}