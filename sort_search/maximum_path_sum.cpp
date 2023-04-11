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

int main()
{
    faster();
    ll n;
    cin >> n;
    ll a[n][n], b[n][n];
    ms(b);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                b[i][j] = a[i][j];
            }
            else
            {
                if (i == 0)
                {
                    b[i][j] = a[i][j];
                }
                else
                {
                    if (j == 0)
                    {
                        b[i][j] = a[i][j] + max(b[i - 1][j], b[i - 1][j + 1]);
                    }
                    else
                    {
                        if (j == n - 1)
                        {
                            b[i][j] = a[i][j] + max(b[i - 1][j], b[i - 1][j - 1]);
                        }
                        else
                            b[i][j] = a[i][j] + max({b[i - 1][j], b[i - 1][j - 1], b[i - 1][j + 1]});
                    }
                }
            }
        }
    }
    ll res = -1;
    for (ll i = 0; i < n; i++)
    {
        res = max(res, b[n - 1][i]);
    }
    cout << res << endl;
}