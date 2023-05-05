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

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cin.ignore(1);
        map<string, ll> mp;
        ll d[2][30] = {};
        ms(d);
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            ans += d[0][s[0] - 'a'] + d[1][s[1] - 'a'] - mp[s] * 2;
            mp[s]++;
            d[0][s[0] - 'a']++;
            d[1][s[1] - 'a']++;
        }
        cout << ans << endl;
    }
}