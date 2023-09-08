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
        ll n, s;
        cin >> n >> s;
        priority_queue<ll, vector<ll>, greater<ll>> qe;
        bool ok = false;
        ll st = 0;
        if (st == s)
            ok = 1;
        set<ll> se;
        for (ll i = 1; i <= n * 3; i++)
        {
            ll x;
            cin >> x;
            if (x <= s)
                se.insert(x);
        }
        for (auto x : se)
        {
            st |= x;
            if (st == s)
            {
                ok = 1;
                break;
            }
            if (st > s)
                break;
        }
        if (ok == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}