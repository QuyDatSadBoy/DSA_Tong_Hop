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
    cin.ignore();
    while (t--)
    {
        ll n;
        cin >> n;
        cin.ignore();
        string a[n];
        map<string, bool> mp;
        for (auto &x : a)
        {
            cin >> x;
            mp[x] = true;
        }
        for (ll i = 0; i < n; i++)
        {
            bool ok = 0;
            for (ll j = 0; j < a[i].size(); j++)
            {
                string t1 = a[i].substr(0, j);
                string t2 = a[i].substr(j);
                if (mp[t1] && mp[t2])
                {
                    ok = 1;
                    break;
                }
            }
            cout << ok;
        }
        cout << endl;
    }
}