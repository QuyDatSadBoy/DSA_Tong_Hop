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
        ll n, m, k, h, cnt = 0;
        cin >> n >> m >> k >> h;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (abs(x - h) / k < m && x != h && abs(x - h) % k == 0)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}