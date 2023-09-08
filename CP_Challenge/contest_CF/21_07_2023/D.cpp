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
    ll Test;
    cin >> Test;
    while (Test--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n + 1] = {0};
        for (ll i = 0; i <= n - 1; i++)
            cin >> a[i];
        stable_sort(a, a + n);
        set<ll> s;
        ll cnt = 1;
        for (ll i = 0; i <= n - 2; i++)
        {
            if (a[i + 1] - a[i] > k)
            {
                s.insert(cnt);
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        s.insert(cnt);
        cout << n - *s.rbegin() << endl;
    }
    return 0;
}
