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
ll f[94];
void init()
{
    f[1] = 1;
    f[2] = 1;
    for (ll i = 3; i <= 93; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
}
ll answer(ll n, ll k)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (k <= f[n - 2])
        return answer(n - 2, k);
    else
    {
        return answer(n - 1, k - f[n - 2]);
    }
}
int main()
{
    faster();
    init();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << answer(n, k) << endl;
    }
}