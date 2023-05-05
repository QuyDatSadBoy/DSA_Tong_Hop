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
        ll n, k;
        cin >> n >> k;
        ll a[n];
        map<ll, ll> mp;
        vector<ll> v;
        for (auto &x : a)
        {
            cin >> x;
            mp[x]++;
        }
        for (auto &x : mp)
        {
            if (x.second >= k)
                v.push_back(x.first);
        }
        if (v.size())
        {
            ll ans = 1, cnt = 1, l = v[0], r = v[0];
            for (ll i = 1; i < v.size(); i++)
            {
                if (v[i] == v[i - 1] + 1)
                {
                    cnt++;
                    if (cnt > ans)
                    {
                        ans = cnt;
                        r = v[i];
                        l = v[i - (cnt - 1)];
                    }
                }
                else
                {
                    cnt = 1;
                    if (cnt > ans)
                    {
                        ans = cnt;
                        r = v[i];
                        l = v[i - (cnt - 1)];
                    }
                }
            }
            cout << l << " " << r << endl;
        }
        else
            cout << -1 << endl;
    }
}