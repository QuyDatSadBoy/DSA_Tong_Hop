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
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();
    s = "@" + s;
    t = "@" + t;
    ll f[n + 1][m + 1];
    ms(f);
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (s[i] == t[j])
            {
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}