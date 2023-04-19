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
ll n, st, t, a[1001][1001], visited[1000001] = {0}, parent[1000001];
void init()
{
    cin >> n >> st >> t;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
}
void dfs(ll s)
{
    visited[s] = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (a[s][i] && !visited[i])
        {
            parent[i] = s;
            dfs(i);
        }
    }
}
void bfs(ll s)
{
    ms(visited);
    queue<ll> qe;
    qe.push(s);
    visited[s] = 1;
    while (!qe.empty())
    {
        ll top = qe.front();
        qe.pop();
        for (ll i = 1; i <= n; i++)
        {
            if (a[top][i] && !visited[i])
            {
                parent[i] = top;
                qe.push(i);
                visited[i] = 1;
            }
        }
    }
}
void solve()
{
    init();
    bfs(st);
    vector<ll> path;
    if (visited[t] == 0)
        cout << "Ko co duong di" << endl;
    else
    {
        path.push_back(t);
        while (t != st)
        {
            t = parent[t];
            path.push_back(t);
        }
        reverse(all(path));
        for (auto x : path)
            cout << x << " ";
        cout << endl;
    }
}
int main()
{
    faster();
    solve();
}