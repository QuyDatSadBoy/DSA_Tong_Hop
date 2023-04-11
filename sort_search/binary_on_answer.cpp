#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll n, k, a[1000001];
bool check(ll mid)
{
    ll sum = 0;
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > mid)
        {
            cnt++;
            sum = a[i];
        }
    }
    if (sum > 0)
        cnt++;
    return cnt <= k;
}

int main()
{
    faster();
    ll l = 0, r = 0;
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    ll res = -1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << res << endl;
}