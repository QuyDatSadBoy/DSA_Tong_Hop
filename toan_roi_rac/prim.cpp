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
vector<edge> edges;
void init()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (j > i && a[i][j] != 0)
            {
                edges.push_back({i, j, a[i][j]});
            }
        }
    }
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
    cout << "ds canh ban dau : " << endl;
    for (auto x : edges)
    {
        cout << x.x << " " << x.y << " " << x.w << endl;
    }
    vector<edge> path;
    ll cnt = 0;
    cout << "oke1" << endl;
    while (!check())
    {
        if (cnt == n - 1)
            break;
        for (ll i = 0; i < edges.size(); i++)
        {
            ll x = edges[i].x, y = edges[i].y, w = edges[i].w;
            if (visited[x] != visited[y])
            {
                cnt++;
                d += w;
                visited[x] = visited[y] = 1;
                path.push_back({x, y, w});
                break;
            }
        }
    }
    if (cnt != n - 1)
        cout << "Do thi khong lien thong" << endl;
    else
        cout << d << endl;
    cout << "Ds canh duoc chon la:" << endl;
    for (auto x : path)
    {
        cout << x.x << " " << x.y << " " << x.w << endl;
    }
}
int main()
{
    // faster();
    init();
    prim(1);
}