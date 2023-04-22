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
ll a[1001][1001], visited[1000001], n;
void init()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
}
void bfs(ll s)
{
    queue<ll> qe;
    qe.push(s);
    visited[s] = 1;
    cout << s << " ";
    while (!qe.empty())
    {
        ll top = qe.front();
        qe.pop();
        for (ll i = 1; i <= n; i++)
        {
            if (a[top][i] && !visited[i])
            {
                cout << i << " ";
                qe.push(i);
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    faster();
    init();
    bfs(1);
}