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
    ll n, m;
    cin >> n >> m;
    ll a[n][m], b[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                b[i][j] = a[i][j];
            }
            else
            {
                if (i == 0)
                {
                    if (j != m - 1)
                        b[i][j] = min({b[i][j - 1], b[i][j + 1], b[i + 1][j]}) + a[i][j];
                    else
                    {
                        b[i][j] = min(b[i][j - 1], b[i + 1][j]) + a[i][j];
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        if (i != n - 1)
                            b[i][j] = min({b[i - 1][j], b[i + 1][j], b[i][j + 1]}) + a[i][j];
                        else
                        {
                        }
                    }
                    else
                    {
                        if (i == n - 1 && j != m - 1 && j != 0)
                        {
                            b[i][j] = min({b[i][j - 1], b[i][j + 1], b[i - 1][j]}) + a[i][j];
                        }
                        else
                        {
                            if (j == m - 1 && i != 0 && i != n - 1)
                            {
                                b[i][j] = min({b[i - 1][j], b[i + 1][j], b[i][j - 1]}) + a[i][j];
                            }
                            else
                            {
                                b[i][j] = min({b[i][j - 1], b[i][j + 1], b[i + 1][j], b[i - 1][j]}) + a[i][j];
                            }
                        }
                    }
                }
            }
        }
    }
    cout << b[n - 1][m - 1] << endl;
}