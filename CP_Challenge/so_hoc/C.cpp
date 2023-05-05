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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        ll ans = 0, cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
            {
                cnt++;
            }
        }
        ans = (n - cnt) * cnt + cnt * (cnt - 1) / 2;
        for (ll i = 0; i < n - 1; i++)
        {
            if (a[i] % 2)
            {
                for (ll j = i + 1; j < n; j++)
                {
                    if (a[j] % 2)
                    {
                        if (__gcd(a[i], a[j]) > 1)
                            ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}