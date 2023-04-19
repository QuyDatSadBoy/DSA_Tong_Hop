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
    vector<ll> f(n + 1, 1e9);
    f[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        f[i] = i;
        for (ll j = 1; j <= sqrt(i); j++)
        {
            f[i] = min(f[i], f[i - j * j] + 1);
        }
    }
    cout << f[n] << endl;
}