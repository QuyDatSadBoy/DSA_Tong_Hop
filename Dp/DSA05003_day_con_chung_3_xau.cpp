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

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        cin.ignore(1);
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        s1 = "@" + s1;
        s2 = "@" + s2;
        s3 = "@" + s3;
        ll f[x + 1][y + 1][z + 1];
        ms(f);
        for (ll i = 1; i <= x; i++)
        {
            for (ll j = 1; j <= y; j++)
            {
                for (ll k = 1; k <= z; k++)
                {
                    if (s1[i] == s2[j] && s1[i] == s3[k])
                    {
                        f[i][j][k] = f[i - 1][j - 1][k - 1] + 1;
                    }
                    else
                    {
                        f[i][j][k] = max({f[i - 1][j][k], f[i][j - 1][k], f[i][j][k - 1]});
                    }
                }
            }
        }
        cout << f[x][y][z] << endl;
    }
}