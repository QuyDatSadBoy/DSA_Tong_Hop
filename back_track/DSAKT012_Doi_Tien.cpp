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
ll n, s, a[31], ans = oo, ok = 0;
void back_track(ll pos, ll sum, ll cnt)
{
    if (ok == 1)
        return;
    for (ll j = pos; j < n; j++)
    {
        if (sum + a[j] <= s)
        {
            if (sum + a[j] == s)
            {
                ans = min(ans, cnt);
                ok = 1;
                return;
            }
            else
                back_track(j + 1, sum + a[j], cnt + 1);
        }
    }
}
int main()
{
    faster();
    cin >> n >> s;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<ll>());
    back_track(0, 0, 1);
    if (!ok)
        cout << -1 << endl;
    else
        cout << ans << endl;
}