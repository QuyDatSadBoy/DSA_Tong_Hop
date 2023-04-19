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
    ll f[n + 1] = {0};
    f[0] = a[0];
    f[1] = max(a[0], a[1]);
    for (ll i = 2; i < n; i++)
    {
        f[i] = max(a[i] + f[i - 2], f[i - 1]);
    }
    cout << f[n - 1] << endl;
}