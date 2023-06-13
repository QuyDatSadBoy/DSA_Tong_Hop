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
ll Hash[maxn], Pow[maxn], f[maxn];
ll getHash(int l, int r)
{
    return ((Hash[r] - Hash[l - 1] * Pow[r - l + 1]) % mod + mod) % mod;
}
int main()
{
    faster();
    Pow[0] = 1;
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for (int i = 1; i <= n; i++)
    {
        Hash[i] = (Hash[i - 1] * 31 + s[i] - 'a' + 1) % mod;
        Pow[i] = Pow[i - 1] * 31 % mod;
    }
    for (int i = 1; i <= m; i++)
    {
        f[i] = (f[i - 1] * 31 + t[i] - 'a' + 1) % mod;
    }
    for (ll i = 1; i + m - 1 <= n; i++)
    {
        if (getHash(i, i + m - 1) == f[m])
        {
            cout << i << " ";
        }
    }
}