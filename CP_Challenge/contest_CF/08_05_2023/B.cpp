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
ll n, m;
ll a[1000006];
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (ll i = 0; i < n * m; i++)
            cin >> a[i];
        sort(a, a + n * m);
        ll min1 = a[0], min2 = a[1], max1 = a[n * m - 1], max2 = a[n * m - 2];
        ll ans = 0;
        ll dem1 = 0 + (max1 - min2) + (max1 - min1);
        ll dem2 = 0 + (max2 - min1) + (max1 - min1);
        if (dem1 > dem2)
        {
            ans = (max1 - min2) * (n - 1) + (n * m - n) * (max1 - min1);
            ll ans2 = (max1 - min2) * (m - 1) + (n * m - m) * (max1 - min1);
            ans = max(ans, ans2);
        }
        else
        {
            ans = (max2 - min1) * (m - 1) + (n * m - m) * (max1 - min1);
            ll ans1 = (max2 - min1) * (n - 1) + (n * m - n) * (max1 - min1);
            ans = max(ans, ans1);
        }
        cout << ans << endl;
        ms(a);
    }
}