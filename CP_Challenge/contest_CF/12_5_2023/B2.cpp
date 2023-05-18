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
ll n, q, a[maxn], sum = 0;
void init()
{
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n + 1);
}
int main()
{
    faster();
    ll T;
    cin >> T;
    while (T--)
    {
        init();
        ll l = 1, r = n;
        for (ll i = 1; i <= q; i++)
        {
            if (q - i >= 1 && (r - l + 1) >= 4)
            {
                ll sum1 = a[l] + a[l + 1] + min(a[l + 2] + a[l + 3], a[r]);
                ll sum2 = a[r] + min(a[l + 1] + a[l + 2], a[r - 1]);
                if (sum1 < sum2) // xoa cai 1
                {
                    sum -= (a[l] + a[l + 1]);
                    l += 2;
                }
                else // xoa cai 2
                {
                    sum -= a[r];
                    r--;
                }
            }
            else
            {
                ll ok = 0;
                if (a[l] + a[l + 1] < a[r]) //  tru di l va l+1
                {
                    ok = 1;
                }
                else
                    ok = 0; // tru di r
                if (ok == 1)
                {
                    sum -= (a[l] + a[l + 1]);
                    l += 2;
                }
                else
                {
                    sum -= a[r];
                    r--;
                }
            }
        }
        cout << sum << endl;
        sum = 0;
    }
}