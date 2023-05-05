#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"
ll n, m;
vector<ll> adj[1000001];
ll visited[1000001];
int main()
{
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    priority_queue<ll, vector<ll>, greater<ll>> qe;
    qe.push(1);
    visited[1] = 1;
    while (qe.size())
    {
        ll u = qe.top();
        cout << u << " ";
        qe.pop();
        for (auto x : adj[u])
        {
            if (visited[x] == 0)
            {
                qe.push(x);
                visited[x] = 1;
            }
        }
    }

    return 0;
}