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
struct qd
{
    ll l, r, k, i, type;
};
set<pair<ll, ll>> se;
qd a[1000001];
bool cmp(qd x, qd y)
{
    if (x.l != y.l)
    {
        return x.l < y.l;
    }
    else
    {
        if (x.r != y.r)
        {
            return x.r > y.r;
        }
        else
        {
            return x.type < y.type;
        }
    }
}
vector<ll> ans(1000001, 0);
int main()
{
    faster();
    ll m;
    cin >> m;
    for (ll i = 1; i <= m; i++)
    {
        qd x;
        cin >> x.l >> x.r;
        x.i = i, x.type = 1;
        a[i] = x;
    }
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        qd x;
        cin >> x.l >> x.r >> x.k;
        x.i = i, x.type = 0;
        a[++m] = x;
    }
    sort(a + 1, a + m + 1, cmp);
    for (ll i = 1; i <= m; i++)
    {
        auto x = a[i];
        if (x.type)
        {
            auto it = se.lower_bound({x.r, 0});
            if (it == se.end())
            {
                return cout << "NO", 0;
            }
            ll j = (it)->second; // vi tri ca si
            ans[x.i] = a[j].i;
            a[j].k--;
            if (a[j].k == 0)
                se.erase(it);
        }
        else
            se.insert({a[i].r, i});
    }
    cout << "YES" << endl;
    for (ll i = 1; i <= m; i++)
    {
        if (ans[i])
            cout << ans[i] << " ";
    }
    cout << endl;
}