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
struct job
{
    ll f, s, w;
};
ll idex(job a[], ll n)
{
    ll l = 0, r = n - 1, i = -1;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (a[m].s < a[n].f)
        {
            i = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return i;
}
int main()
{
    faster();
    ll n;
    cin >> n;
    job a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].f >> a[i].s >> a[i].w;
    }
    sort(a, a + n, [](job a, job b) -> bool
         { return a.s < b.s; });
    ll ans[n] = {0};
    ans[0] = a[0].w;
    for (ll i = 1; i < n; i++)
    {
        ll res = a[i].w;
        ll pos = idex(a, i);
        if (pos != -1)
        {
            res += ans[pos];
        }
        ans[i] = max(res, ans[i - 1]);
    }
    cout << ans[n - 1] << endl;
}