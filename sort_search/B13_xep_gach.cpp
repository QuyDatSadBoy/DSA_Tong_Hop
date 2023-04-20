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
    sort(a, a + n, greater<ll>());
    ll res = 1, docung = a[0];
    for (ll i = 1; i < n; i++)
    {
        docung = min(docung - 1, a[i]);
        if (docung > 0)
            res++;
    }
    cout << res << endl;
}