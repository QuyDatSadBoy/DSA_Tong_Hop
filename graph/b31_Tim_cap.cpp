#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

ll n, f[1000001] = {0};
vector<ll> adj[1000001];
bool visited[1000001] = {0};

ll dfs(ll n)
{
    ll cnt = 1;
    visited[n] = 1;
    for (auto x : adj[n])
    {
        if (!visited[x])
        {
            cnt += dfs(x);
        }
    }
    f[n] = cnt;
    return cnt;
}
int main()
{
    faster();
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            f[i] = dfs(i);
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ans += f[i];
    }
    cout << ans << endl;
    return 0;
}