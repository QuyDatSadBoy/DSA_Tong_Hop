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
    string s1, s2;
    cin >> s1 >> s2;
    ll n = s1.size(), m = s2.size();
    ll f[n + 1][m + 1] = {0};
    s1 = "@" + s1, s2 = "@" + s2;
    for (ll i = 1; i <= n; i++)
    {
        f[i][0] = i;
    }
    for (ll i = 1; i <= m; i++)
    {
        f[0][i] = i;
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (s1[i] == s2[j])
            {
                f[i][j] = f[i - 1][j - 1];
            }
            else
            {
                f[i][j] = min({f[i - 1][j - 1], f[i][j - 1], f[i - 1][j]}) + 1;
            }
        }
    }
    cout << f[n][m] << endl;
}