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
        ll n, x, y, z;
        cin >> n >> x >> y >> z;
        ll f[n + 1] = {0};
        f[1] = x;
        for (ll i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                f[i] = min(f[i - 1] + x, f[(i / 2)] + z);
            }
            else
                f[i] = min(f[i - 1] + x, f[(i + 1) / 2] + y + z);
        }
        cout << f[n] << endl;
    }
}