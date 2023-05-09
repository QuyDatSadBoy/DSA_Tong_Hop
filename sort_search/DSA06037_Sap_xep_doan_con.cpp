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
        ll Max[n], Min[n], a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        Max[0] = a[0], Min[n - 1] = a[n - 1];
        for (ll i = 1; i < n; i++)
            Max[i] = max(a[i], Max[i - 1]);
        for (ll i = n - 2; i >= 0; i--)
            Min[i] = min(a[i], Min[i + 1]);
        vector<ll> ans;
        for (ll i = 0; i < n - 1; i++)
        {
            if (Max[i] <= Min[i + 1])
                ans.push_back(i);
        }
        if (ans.size())
        {
            cout << ans.size() << endl;
            for (auto &x : ans)
                cout << x + 1 << " ";
            cout << endl;
        }
        else
            cout << 0 << endl;
    }
}