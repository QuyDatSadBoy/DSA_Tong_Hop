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
ll prime[1000001];
void sieve()
{
    for (int i = 2; i <= 1000000; i++)
        prime[i] = i;
    for (ll i = 2; i <= sqrt(1000000); i++)
    {
        if (prime[i] == i)
        {
            for (ll j = i * i; j <= 1000000; j += i)
            {
                if (prime[j] == j)
                    prime[j] = i;
            }
        }
    }
}
int main()
{
    faster();
    sieve();
    ll n, ans = 0;
    cin >> n;
    while (n--)
    {
        ll x;
        cin >> x;
        while (x != 1)
        {
            ans += prime[x];
            x /= prime[x];
        }
    }
    cout << ans << endl;
}