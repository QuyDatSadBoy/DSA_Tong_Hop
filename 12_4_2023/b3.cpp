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
    ll n, m;
    cin >> n >> m;
    ll a[n][m], b[n][m];
    ms(b);
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
                    b[i][j] = a[i][j] + b[i][j - 1];
                }
                else
                {
                    if (j == 0)
                    {
                        b[i][j] = a[i][j] + b[i - 1][j];
                    }
                    else
                    {
                        b[i][j] = a[i][j] + max(b[i - 1][j], b[i][j - 1]);
                    }
                }
            }
        }
    }

    cout << b[n - 1][m - 1] << endl;
}