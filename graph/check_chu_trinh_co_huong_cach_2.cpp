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

vector<ll> adj[100001];
ll n, m, visited[1000001] = {0}, parent[1000001] = {0}, color[1000001] = {0};

void init_vh()
{
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (ll i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
    }
}
void init_ch()
{
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (ll i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
    }
}
bool dfs(ll u)
{
    color[u] = 1;
    for (auto x : adj[u])
    {
        if (!color[x])
        {
            if (!dfs(x))
                return false;
        }
        else if (color[x] == 1)
            return false;
    }
    color[u] = 2;
    return true;
}

void solve()
{
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (!dfs(i))
            {
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
    return;
}
int main()
{
    faster();
    init_ch();
    solve();
}