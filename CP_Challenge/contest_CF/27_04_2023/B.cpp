#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
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
        ll n, k, ans = 0;
        cin >> n >> k;
        pair<ll, ll> a[n + 1];
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a + 1, a + n + 1);
        for (ll i = 1; i <= n; i++)
        {
            ll dem = a[i].second - i;
            if (dem % k != 0)
            {
                ans++;
            }
        }
        if (ans == 0)
            cout << 0 << endl;
        else
        {
            if (ans == 2)
                cout << 1 << endl;
            else
                cout << -1 << endl;
        }
    }
}