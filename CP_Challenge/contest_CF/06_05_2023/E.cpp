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
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
ll a[1005][1005], n, m;
ll sum = 0;
void dfs(ll i, ll j)
{
    sum += a[i][j];
    a[i][j] = 0;
    for (ll k = 0; k < 4; k++)
    {
        ll imoi = i + dx[k];
        ll jmoi = j + dy[k];
        if (imoi >= 0 && imoi < n && jmoi >= 0 && jmoi < m && a[imoi][jmoi] != 0)
        {
            dfs(imoi, jmoi);
        }
    }
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (a[i][j] != 0)
                {
                    sum = 0;
                    dfs(i, j);
                    res = max(res, sum);
                }
            }
        }
        cout << res << endl;
    }
}