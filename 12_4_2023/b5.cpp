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
ll n, m, s, t, visited[100001] = {0};
int parent[100001]; // lưu cha của đỉnh u

void init_vh()
{
    cin >> n >> m >> s;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void bfs(ll u)
{
    queue<ll> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        for (auto y : adj[x])
        {
            if (!visited[y])
            {
                q.push(y);
                visited[y] = true;
                parent[y] = x;
            }
        }
    }
}

int main()
{
    faster();
    ll test;
    cin >> test;
    while (test--)
    {
        ms(visited);
        ms(parent);
        init_vh();
        for (ll i = 1; i <= n; i++)
        {
            if (i == s)
                continue;
            t = i;
            bfs(s);
            if (visited[t])
            {
                vector<ll> way;
                way.push_back(t);
                while (s != t)
                {
                    t = parent[t];
                    way.push_back(t);
                }
                reverse(all(way));
                for (auto x : way)
                {
                    cout << x << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "No path" << endl;
            }
            ms(visited);
            ms(parent);
        }
        for (auto x : adj)
        {
            x.clear();
        }
        ms(visited);
        ms(parent);
    }
}