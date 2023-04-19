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
ll n, u, a[1001][1001], visited[1000001], x[1000001];
void init()
{
    cin >> n >> u;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    x[1] = u;
    visited[u] = 1;
}
void hamilton(ll k)
{
    for (ll i = 1; i <= n; i++)
    {
        if (a[x[k - 1]][i] && !visited[i])
        {
            x[k] = i;
            visited[i] = 1;
            if (k == n)
            {
                for (ll i = 1; i <= n; i++)
                    cout << x[i] << " ";
                cout << x[1];
                cout << endl;
            }
            else
            {
                hamilton(k + 1);
            }
            visited[i] = 0;
        }
    }
}
int main()
{
    faster();
    init();
    hamilton(2);
}