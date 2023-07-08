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
        ll n, m;
        cin >> n >> m;
        ll a[n + 1], b[m + 1];
        ll sum1 = 0, sum2 = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum1 += a[i];
        }
        for (ll i = 1; i <= m; i++)
        {
            cin >> b[i];
            sum2 += b[i];
        }
        if (sum1 > sum2)
            cout << "Tsondu" << endl;
        else if (sum1 < sum2)
            cout << "Tenzing" << endl;
        else
            cout << "Draw" << endl;
    }
}