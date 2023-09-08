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
        multiset<ll> se;
        ll n;
        cin >> n;
        ll a[n], cnt2 = 0, cnt3 = 0, ok = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            se.insert(a[i]);
            if (a[i] >= n)
            {
                cnt3++;
            }
        }
        if (cnt3 == n)
            cout << -1 << endl;
        else
        {
            sort(a, a + n);
            for (ll i = 0; i < n; i++)
            {
                if (a[i] == a[i + 1] && i != n - 1)
                {
                    cnt2++;
                    continue;
                }
                ll idex = i;
                ll tam = a[i];
                ll sz2 = n - i - 1;
                if (sz2 < tam)
                {
                    ok = 1;
                    break;
                }
                else
                {
                    if (binary_search(a + i + 1, a + n, sz2) == true)
                    {
                        ok = 1;
                        break;
                    }
                    else
                        cnt2++;
                }
            }
            if (ok == 1)
                cout << -1 << endl;
            else
                cout << n - cnt2 << endl;
        }
    }
}