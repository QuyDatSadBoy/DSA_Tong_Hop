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
        vector<pair<ll, ll>> p(n);
        ll tam = 0, cnt = 0;
        for (ll i = 0; i <= n - 1; i++)
        {
            cin >> p[i].first >> p[i].second;
            if (p[i].second >= p[i].first)
            {
                tam++;
            }
            else
            {
                cnt++;
            }
        }
        if (tam == n)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << cnt << endl;
        }
        p.clear();
    }
    return 0;
}
