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
    ll time, value, idex;
};
bool cmp(qd a, qd b)
{
    return a.value > b.value;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, s;
        cin >> n >> s;
        ll a[n], b[n];
        vector<qd> v;
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        for (ll i = 0; i < n; i++)
        {
            v.push_back({a[i], b[i], i});
        }
        sort(all(v), cmp);
        ll ans = -1;
        for (ll i = 0; i < n; i++)
        {
            if (s - v[i].idex >= v[i].time)
            {
                ans = v[i].idex + 1;
                break;
            }
        }
        cout << ans << endl;
    }
}