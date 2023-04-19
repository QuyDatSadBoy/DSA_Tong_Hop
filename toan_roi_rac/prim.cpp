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
// chuyen tu ma tran ke sang danh sach canh do thi vo huong
struct edge
{
    ll x, y, w;
};
ll n, m, a[1001][1001], visited[1000001];
set<pair<ll, ll>> se;
vector<edge> edges;
void init()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
                se.insert({min(i, j), max(i, j)});
        }
    }
    for (auto x : se)
    {
        ll s = x.first;
        ll t = x.second;
        edges.push_back({s, t, a[s][t]});
    }
    m = edges.size(); // so luong canh
}
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
bool check() // check xem da duyet het dinh chua
{
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}
void prim(ll s)
{
    visited[s] = 1;
    ll d = 0;
    sort(all(edges), cmp);
    cout << "ds canh" << endl;
    for (auto x : edges)
    {
        cout << x.x << " " << x.y << " " << x.w << endl;
    }
    ll cnt = 0;
    while (!check())
    {
        if (cnt == n - 1)
            break;
        for (ll i = 0; i < m; i++)
        {
            ll x = edges[i].x, y = edges[i].y, w = edges[i].w;
            if (visited[x] != visited[y])
            {
                cnt++;
                d += w;
                visited[x] = visited[y] = 1;
                break;
            }
        }
    }
    if (cnt != n - 1)
        cout << "Do thi khong lien thong" << endl;
    else
        cout << d << endl;
}
int main()
{
    faster();
    init();
    prim(1);
}