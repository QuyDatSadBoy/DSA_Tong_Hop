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
ll f[maxn], d[maxn], ans = 0, n;
void sieve()
{
    for (ll i = 1; i < maxn; i++)
    {
        for (ll j = i; j < maxn; j += i)
        {
            if (d[j])
                f[i] = __gcd(f[i], j);
        }
        ans += f[i] == i;
    }
    cout << ans - n << endl;
}
int main()
{
    faster();
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        d[x] = 1;
    }
    sieve();
}