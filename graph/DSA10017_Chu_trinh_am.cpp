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
// Bellman Ford
// co the ap ung cho co canh am nhung khong co chu trinh am
ll n, m;
struct edge
{
    ll x, y, w;
};
vector<edge> edges;
ll d2[1001][1001];
void init()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (i == j)
                d2[i][j] = 0;
            else
                d2[i][j] = (int)1e9;
        }
    }
    for (int i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
        d2[x][y] = d2[y][x] = w;
    }
}
void bellManFord(int s)
{
    ll d[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        d[i] = (int)1e19;
    }
    d[s] = 0;
    for (ll i = 1; i <= n - 1; i++)
    {
        for (auto it : edges)
        {
            ll u = it.x, v = it.y, w = it.w;
            if (d[u] != (ll)1e18 && d[v] > d[u] + w)
                d[v] = d[u] + w;
        }
    }
    ll ok = 1;
    for (auto it : edges)
    {
        ll u = it.x, v = it.y, w = it.w;
        if (d[u] != (int)1e9 && d[v] > d[u] + w)
        {
            d[v] = d[u] + w;
            ok = 0;
            break;
        }
    }
    if (ok == 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

// Floyd tim duong di cua moi cap dinh tren do thi
void Floyd()
{
    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
            }
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << d2[x][y] << endl;
    }
}

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        init();
        bellManFord(1);
        edges.clear();
    }
}