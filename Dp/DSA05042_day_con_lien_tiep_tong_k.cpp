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
        ll n, s, sum = 0, ok = 0;
        cin >> n >> s;
        ll a[n];
        for (auto &x : a)
        {
            cin >> x;
            if (x == 0)
                ok = 1;
        }
        map<ll, bool> mp;
        mp[0] = true;
        for (ll i = 0; i < n; i++)
        {
            sum += a[i];
            if (mp[sum - s])
                mp[s] = true;
            mp[sum] = true;
        }
        if (s == 0)
        {
            if (ok == 0)
                cout << "NO" << endl;
            else
            {
                if (mp[s])
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
        else
        {
            if (mp[s])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}