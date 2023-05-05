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
ll n, a[20][20], f[1 << 20], cnt[1 << 20];
int main()
{
    faster();
    cnt[0] = 1;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for (ll x = 1; x < (1 << n); x++)
    {
        ll k = __builtin_popcountll(x) - 1;
        for (ll i = 0; i < n; i++)
        {
            if (bit(x, i))
            {
                ll pre = x - (1 << i);
                if (f[x] < f[pre] + a[k][i])
                {
                    f[x] = f[pre] + a[k][i];
                    cnt[x] = cnt[pre];
                }
                else if (f[x] == f[pre] + a[k][i])
                    cnt[x] += cnt[pre];
            }
        }
    }
    cout << f[(1 << n) - 1] << " " << cnt[(1 << n) - 1] << endl;
}