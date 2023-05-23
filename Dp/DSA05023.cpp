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
    cin.ignore(1);
    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.size();
        s = "@" + s;
        ll f[n + 1] = {0}, sum = 0;
        f[1] = s[1] - '0';
        for (ll i = 2; i <= n; i++)
        {
            f[i] = f[i - 1] * 10 + i * (s[i] - '0');
        }
        for (ll i = 1; i <= n; i++)
            sum += f[i];
        cout << sum << endl;
    }
}