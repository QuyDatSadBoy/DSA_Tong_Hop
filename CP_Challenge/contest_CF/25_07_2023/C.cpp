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
ll a[1000000] = {0};
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cin >> a[0];
        ll x = a[0], cnt = 1, pos = 0;
        for (ll i = 1; i < n; i++)
        {
            ll tam;
            cin >> tam;
            a[i] = tam;
            if (cnt < k && a[i] == x)
            {
                cnt++;
                pos = i;
            }
            else
            {
            }
        }
        bool ok = false;
        if (cnt == k)
        {
            if (a[0] == a[n - 1])
                ok = true;
            else
            {
                ll cnt1 = 1, y = a[n - 1];
                for (ll i = n - 2; i >= pos; i--)
                {
                    if (cnt1 == k)
                    {
                        ok = true;
                        break;
                    }
                    if (a[i] == y)
                    {
                        cnt1++;
                    }
                }
            }
        }
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
