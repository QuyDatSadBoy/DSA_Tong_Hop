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
ll n, m, color[1000001] = {0};
vector<ll> adj[1000001];

void init()
{
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
bool dfs(ll u, ll par)
{
    color[u] = 3 - color[par];
    for (auto x : adj[u])
    {
        if (color[x] == 0)
        {
            if (!dfs(x, u))
                return false;
        }
        else if (color[u] == color[x])
            return false;
    }
    return true;
}
int main()
{
    faster();
    init();
    color[0] = 2;
    for (ll i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            color[0] = 2;
            if (!dfs(i, 0))
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}