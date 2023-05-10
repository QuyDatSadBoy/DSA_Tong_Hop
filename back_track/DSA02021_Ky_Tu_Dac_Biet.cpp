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
ll sz;
char back_track(ll k, string s, ll n)
{
    if (k <= sz)
        return s[k];
    if (k <= n / 2)
        return back_track(k, s, n / 2);
    if (k == (n / 2) + 1)
        return back_track(k - 1, s, n / 2);
    if (k > (n / 2) + 1)
        return back_track(k - (n / 2) - 1, s, n / 2);
    return 'L';
}
int main()
{
    faster();
    ll t;
    cin >> t;
    cin.ignore(1);
    while (t--)
    {
        string s;
        cin >> s;
        ll k;
        cin >> k;
        cin.ignore(1);
        ll n = s.size();
        sz = s.size();
        s = " " + s;
        while (n < k)
            n *= 2;
        cout << back_track(k, s, n) << endl;
    }
}