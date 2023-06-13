#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define _oo LLONG_MIN
#define oo LLONG_MAX - 9
#define bit(x, i) ((x >> i) & 1)
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll n;
vector<ll> adj[1000001];
ll sum[1000001], val[1000001];
void dfs(ll u)
{
    for (auto &x : adj[u])
    {
        dfs(x);
        sum[u] += sum[x] + 1;
        val[u] += val[x];
    }
    val[u] += sum[u];
}
int main()
{
    faster();
    cin >> n;
    for (ll i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        adj[x].push_back(i);
    }
    for (ll i = 1; i <= n; i++)
    {
        sum[i] = 0;
        val[i] = 1;
    }
    dfs(1);
    for (ll i = 1; i <= n; i++)
        cout << val[i] << " ";
    cout << endl;
}