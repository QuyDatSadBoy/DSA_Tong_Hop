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
ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, n, ans = (ll)1e18;
void back_track(ll i, ll k, ll x)
{
    if (x > n)
        return;
    if (x == n)
        ans = min(ans, k);
    for (ll j = 1;; j++)
    {
        if (k * prime[i] > ans)
            break;
        k *= prime[i];
        back_track(i + 1, k, x * (j + 1));
    }
}

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 1e18;
        back_track(0, 1, 1);
        cout << ans << endl;
    }
}