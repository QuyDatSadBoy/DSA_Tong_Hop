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
        ll a[n];
        for (auto &x : a)
            cin >> x;
        sort(a, a + n);
        ll l = n / 2, r = n - 1, res = 0;
        while (r > (n / 2) && l > 0)
        {
            if (a[l] * 2 <= a[r])
            {
                r--;
                l--;
                res++;
            }
            else
            {
                l--;
                res++;
            }
        }
        if (l > 0)
        {
            res += l;
        }
        if (r > (n / 2))
            res += r - (n / 2);
        cout << res << endl;
    }
}