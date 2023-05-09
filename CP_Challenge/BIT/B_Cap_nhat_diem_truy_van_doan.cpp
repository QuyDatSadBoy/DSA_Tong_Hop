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
ll n, q, a[maxn], t[maxn];
void update(ll x, ll value)
{
    while (x <= n)
    {
        t[x] += value;
        x += (x & (-x));
    }
}
ll get(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans += t[x];
        x -= (x & (-x));
    }
    return ans;
}
void init()
{
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
}
int main()
{
    faster();
    init();
    while (q--)
    {
        ll type, x, value;
        cin >> type >> x;
        if (type == 1)
        {
            cin >> value;
            update(x, value - a[x]);
            a[x] = value;
        }
        else
            cout << get(x) << endl;
    }
}