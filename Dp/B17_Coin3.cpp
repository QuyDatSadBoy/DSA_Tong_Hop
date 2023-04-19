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
    ll n, s;
    cin >> n >> s;
    ll a[n];
    for (auto &x : a)
        cin >> x;
    ll f[s + 1] = {0};
    f[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j <= s; j++)
        {
            if (j >= a[i])
            {
                f[j] += f[j - a[i]];
                f[j] %= mod;
            }
        }
    }
    cout << f[s] << endl;
}