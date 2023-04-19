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
    ll n;
    cin >> n;
    ll a[n];
    for (auto &x : a)
        cin >> x;
    map<ll, ll> mp;
    ll c = 0, l = 0, res = 0;
    mp[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            c++;
        }
        else
            l++;
        res += mp[c - l];
        mp[c - l]++;
    }
    cout << res << endl;
}