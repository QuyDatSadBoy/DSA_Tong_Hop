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

vector<ll> adj[10001];
ll n, m, visited[100001] = {0};
vector<pair<ll, ll>> edge;

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
}
void dfs(ll i)
{
    visited[i] = true;
    for (auto x : adj[i])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
}

int main()
{
    faster();
    init_vh();
    for (ll i = 1; i <= n; i++)
    {
        ll cnt = 0;
        visited[i] = true;
        for (ll j = 1; j <= n; j++)
        {
            if (!visited[j])
            {
                cnt++;
                dfs(j);
            }
        }
        cout << cnt << endl;
        ms(visited);
    }
}