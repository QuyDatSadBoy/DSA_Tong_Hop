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
        ll n;
        cin >> n;
        ll a[n] = {0};
        ll tam = n - 1;
        ll cnt1 = 0, cnt2 = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (n % a[i] == 0)
                cnt1++;
            if (tam % a[i] == 0)
                cnt2++;
        }
        ll res = 0;
        if (n > 1)
            res = max({res, cnt1, cnt2});
        cout << res << endl;
    }
}