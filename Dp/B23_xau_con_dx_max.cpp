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
    string s;
    cin >> s;
    ll n = s.size(), res = -1e9;
    s = "@" + s;
    bool f[n + 1][n + 1];
    ms(f);
    for (ll i = 1; i <= n; i++)
    {
        f[i][i] = true;
    }
    for (ll k = 2; k <= n; k++)
    {
        for (ll i = 1; i < n - k + 1; i++)
        {
            ll j = i + k - 1;
            if (s[j] == s[i])
            {
                if (k == 2)
                    f[i][j] = true;
                else
                    f[i][j] = f[i + 1][j - 1];
            }
            if (f[i][j])
                res = max(res, j - i + 1);
        }
    }
    cout << res << endl;
}