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

bool cmp1(pair<ll, ll> x, pair<ll, ll> y)
{
    return x.second < y.second;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll b[n];
        pair<ll, ll> a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (ll i = 0; i < n; ++i)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        for (ll i = 0; i < n; i++)
        {
            a[i].first = b[i];
        }
        sort(a, a + n, cmp1);
        for (ll i = 0; i < n; i++)
        {
            ll value = a[i].first;
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}