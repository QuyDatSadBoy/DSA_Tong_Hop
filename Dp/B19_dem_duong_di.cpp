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

int main()
{
    faster();
    ll n;
    cin >> n;
    char a[n + 1][n + 1];
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    ll f[n + 1][n + 1];
    ms(f);
    f[1][0] = f[0][1] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (a[i][j] == '.')
            {
                if (i == 1)
                {
                    f[i][j] = f[i][j - 1];
                }
                else
                {
                    if (j == 1)
                    {
                        f[i][j] = f[i - 1][j];
                    }
                    else
                    {
                        f[i][j] += f[i - 1][j] + f[i][j - 1];
                    }
                }
                f[i][j] %= mod;
            }
            else
                f[i][j] = 0;
        }
    }
    cout << f[n][n] << endl;
}