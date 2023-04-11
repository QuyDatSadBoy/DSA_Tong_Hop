#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll pow_mod(ll n, ll k)
{
    if (k == 0)
    {
        return 1;
    }
    else
    {
        ll tam = pow_mod(n, k / 2);
        if (k & 1)
        {
            return (tam % mod) * (tam % mod) % mod * (n % mod) % mod;
        }
        else
            return (tam % mod) * (tam % mod) % mod;
    }
}
int main()
{
    faster();
    ll n, k;
    cin >> n >> k;
    cout << pow_mod(n, k) << endl;
}