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

vector<ll> adj[100001], T_adj[1000001];
ll n, m, visited[1000001] = {0}, parent[1000001] = {0};
stack<int> st;

// kiem tra do thi lien thong mang va in ra cac thanh phan lien thong manh ay

void init_ch()
{
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        T_adj[y].push_back(x);
    }
    for (ll i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
    }
}
void dfs(ll u)
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
    st.push(u);
}
void dfs2(ll u)
{
    visited[u] = true;
    for (auto x : T_adj[u])
    {
        if (!visited[x])
        {
            dfs2(x);
        }
    }
}

void solve()
{
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    ms(visited);
    while (!st.empty())
    {
        ll top = st.top();
        st.pop();
        if (!visited[top])
        {
            cnt++;
            dfs2(top);
        }
    }
    if (cnt == 1)
        cout << 1 << endl;
    else
    {
        cout << 0 << endl;
    }
}
int main()
{
    faster();
    init_ch();
    solve();
}