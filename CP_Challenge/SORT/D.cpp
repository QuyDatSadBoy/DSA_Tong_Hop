#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

int main()
{
    // faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n], b[n];
        vector<ll> v1, v2;
        ll sum = 0;
        for (auto &x : a)
        {
            cin >> x;
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
            if (a[i] == 0)
            {
                v1.push_back(b[i]);
            }
            else
                v2.push_back(b[i]);
        }
        sort(all(v1));
        sort(all(v2));
        if (v1.size() == v2.size())
        {
            ll res1 = accumulate(all(v1), 0ll);
            ll res2 = accumulate(all(v2), 0ll);
            cout << (res1 + res2) * 2 - min(v1[0], v2[0]) << endl;
        }
        else
        {
            ll ok = 0;
            ll k = min(v1.size(), v2.size());
            if(v1.size()>v2.size())
            {
                
            }
            
        }
    }
}