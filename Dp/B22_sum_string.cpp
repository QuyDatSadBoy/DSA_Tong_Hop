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
    ll n = s.size();
    ll f[n + 1] = {0};
    s = "@" + s;
    for (ll i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * 10 + (i) * (s[i] - '0');
    }
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        res += f[i];
    }
    cout << res << endl;
}