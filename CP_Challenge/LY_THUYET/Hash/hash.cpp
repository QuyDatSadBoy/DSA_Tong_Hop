#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define base 31
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
string s, t;
ll f[maxn], HashT, p[maxn];
ll getHash(ll l, ll r)
{
    ll ans = ((f[r] - f[l - 1] * p[r - l + 1]) % mod + mod) % mod;
    return ans;
}
int main()
{
    faster();
    cin >> s >> t;
    ll n = s.size(), m = t.size();
    t = " " + t;
    s = " " + s;
    p[0] = 1;
    for (ll i = 1; i <= m; i++)
        p[i] = p[i - 1] * base % mod;
    for (ll i = 1; i <= m; i++)
        HashT = (HashT * base + t[i] - 'a' + 1) % mod;
    for (ll i = 1; i <= n; i++)
        f[i] = (f[i - 1] * base + s[i] - 'a' + 1) % mod;
    for (ll i = 1; i + m - 1 <= n; i++)
    {
        if (HashT == getHash(i, i + m - 1))
            cout << i << " ";
    }
}