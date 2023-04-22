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

void ktao()
{
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
void Union(ll x, ll y)
{
    x = find(x);
    y = find(y);
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
}
int main()
{
    faster();
    // co the lam bai check chu trinh
    ll t;
    cin >> n >> m >> t;
    ktao();
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        Union(x, y);
    }
    ll ok = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (parent[i] != parent[t])
        {
            cout << i << endl;
            ok = 1;
        }
    }
    if (!ok)
        cout << 0 << endl;
}