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
bool check(ll mid, ll a[], ll n)
{
    ll sum = 0, ok = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == mid)
        {
            sum = 0;
            if (i == n - 1)
            {
                return true;
            }
        }
        else
        {
            if (sum > mid)
            {
                return false;
            }
        }
    }
    if (sum == mid)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n], prefix[n];
        ll l = (int)(-1e9), r = 0, res = (int)(1e9);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            l = max(l, a[i]);
            r += a[i];
            if (i == 0)
            {
                prefix[0] = a[0];
            }
            else
            {
                prefix[i] = prefix[i - 1] + a[i];
            }
        }
        ll l1 = 0, r1 = n;
        while (l1 <= r1)
        {
            ll mid = (l1 + r1) / 2;
            if (check(prefix[mid], a, n))
            {
                res = min(prefix[mid], res);
                r1 = mid - 1;
            }
            else
            {
                r1 = mid - 1;
            }
        }
        l1 = 0, r1 = n;
        while (l1 <= r1)
        {
            ll mid = (l1 + r1) / 2;
            if (check(prefix[mid], a, n))
            {
                res = min(prefix[mid], res);
                l1 = mid + 1;
            }
            else
            {
                l1 = mid + 1;
            }
        }
        l1 = 0, r1 = n;
        for (ll i = 0; i < 200; i++)
        {
            ll mid = (l1 + r1) / 2;
            if (check(prefix[mid], a, n))
            {
                res = min(prefix[mid], res);
                r1 = mid;
            }
            else
            {
                r1 = mid;
            }
        }
        l1 = 0, r1 = n;
        for (ll i = 0; i < 200; i++)
        {
            ll mid = (l1 + r1) / 2;
            if (check(prefix[mid], a, n))
            {
                res = min(prefix[mid], res);
                l1 = mid;
            }
            else
            {
                l1 = mid;
            }
        }
        cout << res << endl;
    }
}