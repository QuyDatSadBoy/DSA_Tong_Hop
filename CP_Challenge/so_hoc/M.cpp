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
ll euler[1000001];
void sieve()
{
    for (ll i = 2; i <= 1000000; i++)
        euler[i] = i;
    for (ll i = 2; i <= sqrt(1000000); i++)
    {
        if (euler[i] == i)
        {
            euler[i] = i - 1;
            for (ll j = 2 * i; j <= 1000000; j += i)
            {
                euler[j] -= euler[j] / i;
            }
        }
    }
}
ll calc(ll n)
{
    ll res = n;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n != 1)
        res -= res / n;
    return res;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, m;
        cin >> x >> m;
        ll M = m / __gcd(x, m);
        cout << calc(M) << endl;
    }
}