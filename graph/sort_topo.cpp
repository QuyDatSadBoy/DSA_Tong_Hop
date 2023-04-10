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
ll n, m, visited[1000001] = {0}, degree[1000001];
vector<int> topo;

// sap xep toco khong duoc co chu trinh dung cho do thi co huong
// neu co duong noi tu u den v thi u dung truoc v trong sort toco
// co rat nhieu sort toco thoa man
// co 2 cach theo dfs va bfs
// kahn() dua tren bfs -- xoa dan dinh co 1 mang luu ban bac vao
// kiem tra chu tinh tren do thi co huong dung kahn() no khong in ra du dinh
// thi co chu trinh

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
        degree[y]++;
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
    topo.push_back(u);
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
                visited[y] = true;
                q.push(y);
            }
        }
    }
}
void kahn()
{
    queue<ll> qe;
    for (ll i = 1; i <= n; i++)
    {
        if (!degree[i])
        {
            qe.push(i);
        }
    }
    while (!qe.empty())
    {
        ll top = qe.front();
        qe.pop();
        cout << top << " ";
        for (auto x : adj[top])
        {
            degree[x]--;
            if (degree[x] == 0)
            {
                qe.push(x);
            }
        }
    }
    cout << endl;
}
void solve()
{
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(all(topo));
    for (auto x : topo)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    faster();
    init_ch();
    kahn();
}