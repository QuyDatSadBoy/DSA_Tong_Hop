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
ll n, m, a[1001][1001], visited[1000001] = {0};
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
void dfs(ll s)
{
    visited[s] = 1;
    cout << s << " ";
    for (ll i = 1; i <= n; i++)
    {
        if (a[s][i] && !visited[i])
        {
            dfs(i);
        }
    }
}
int main()
{
    faster();
    init();
    dfs(1);
}