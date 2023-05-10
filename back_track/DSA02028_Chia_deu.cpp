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
ll n, k, a[20], ans = 0, s = 0;
void back_track(ll pos, ll cnt, ll sum)
{
    if (cnt == k && pos == n)
    {
        ans++;
        return;
    }
    for (ll j = pos; j < n; j++)
    {
        sum += a[j];
        if (sum == s)
            back_track(j + 1, cnt + 1, 0);
    }
}
int main()
{
    faster();
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % k != 0)
        cout << 0 << endl;
    else
    {
        vector<ll> v;
        s /= k;
        back_track(0, 0, 0);
        cout << ans << endl;
    }
}