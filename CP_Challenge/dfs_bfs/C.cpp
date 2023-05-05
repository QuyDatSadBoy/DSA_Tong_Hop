#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll a[1005][1005], visited[1000001], n;
void dfs(ll i, ll j, ll &d, ll x)
{
    if (d > x)
        return;
    a[i][j] = x;
    if (j - 1 >= 1 && a[i][j - 1] == 0)
        dfs(i, j - 1, d = d + 1, x);
    if (i + 1 <= n && a[i + 1][j] == 0)
        dfs(i + 1, j, d = d + 1, x);
}
int main()
{
    faster();
    cin >> n;
    ll b[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        cin >> b[i];
        a[i][i] = b[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        ll d = 1;
        dfs(i, i, d, b[i]);
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= i; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}