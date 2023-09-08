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
        ll n, k;
        cin >> n >> k;
        ll res1 = 0, res2 = 0, l, r, ok = 0;
        for (ll i = 0; i <= n / 2; i++)
        {
            ll b = n - i;
            res1 = i * (i - 1) / 2;
            res2 = b * (b - 1) / 2;
            if (res1 + res2 == k)
            {
                ok = 1;
                l = i, r = b;
                break;
            }
        }
        if (ok == 1)
        {
            cout << "YES" << endl;
            for (ll i = 0; i < l; i++)
                cout << 1 << " ";
            for (ll i = 0; i < r; i++)
                cout << -1 << " ";
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
}