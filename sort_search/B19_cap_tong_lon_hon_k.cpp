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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (auto &x : a)
        cin >> x;
    sort(a, a + n);
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        auto idex = upper_bound(a + i + 1, a + n, k - a[i]);
        if (idex != a + n)
        {
            ll pos = idex - a;
            res += (n - 1 - pos) + 1;
        }
    }
    cout << res << endl;
}