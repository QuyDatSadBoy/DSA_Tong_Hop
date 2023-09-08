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
    ll n;
    cin >> n;
    ll a[n + 1] = {0}, f[n + 1] = {0}, p[n + 1] = {0}, ans = 0, res = -1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
        ans += i * a[i];
        res = max(res, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            p[i] = ans;
        }
        else
        {
            ans -= a[i - 1];
            ans -= (f[n] - f[i - 1]);
            p[i] = ans;
        }
        res = max(res, p[i]);
        ll k = n - i + 1;
        for (ll j = n; j > i; j--)
        {
            p[i] -= a[j] * k;
            if (p[i] < res)
                break;
            res = p[i];
            --k;
        }
    }
    cout << res << endl;
}
