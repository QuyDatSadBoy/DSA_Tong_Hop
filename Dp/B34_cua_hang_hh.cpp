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
    ll a[n], res = 0;
    vector<ll> f1(n, 1), f2(n, 1);
    for (auto &x : a)
        cin >> x;
    for (ll i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            f1[i] = f1[i - 1] + 1;
        res = max(res, f1[i]);
    }
    for (ll i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
            f2[i] = f2[i + 1] + 1;
        res = max(res, f2[i]);
    }
    for (ll i = 1; i < n - 1; i++)
    {
        if (a[i + 1] > a[i - 1])
        {
            res = max(res, f1[i - 1] + f2[i + 1]);
        }
    }
    cout << res << endl;
}