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
ll prime[1000006];
void sieve()
{
    for (ll i = 0; i <= 1000005; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (ll i = 2; i <= sqrt(1000005); i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= 1000005; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
ll f[1000006];
vector<ll> v;
int main()
{
    faster();
    sieve();
    for (ll i = 2; i <= 1000005; i++)
        if (prime[i])
            v.push_back(i);
    ll l = 0, r = 0;
    for (ll i = 1; i <= 1000005; i++)
    {
        if (v[r] <= i)
            r++;
        if (v[l] * v[l] <= i)
            l++;
        f[i] = r - l;
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << f[n] + 1 << endl;
    }
}