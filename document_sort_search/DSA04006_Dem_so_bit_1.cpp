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
int check(ll i, ll n, ll cnt)
{
    if (i % 2 == 1)
        return 1;
    else
    {
        ll pos = pow(2, cnt);
        if (pos == i)
            return n % 2;
        else
        {
            if (i < pos)
                return check(i, n / 2, cnt - 1);
            else
                return check(i - pos, n / 2, cnt - 1);
        }
    }
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        ll dem = log2(n);
        ll ans = 0;
        for (ll i = l; i <= r; i++)
        {
            if (check(i, n, dem))
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}