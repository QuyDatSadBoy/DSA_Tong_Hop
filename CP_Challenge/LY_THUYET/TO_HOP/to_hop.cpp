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
ll prime[1000001];
void sieve()
{
    for (ll i = 1; i <= 1000000; i++)
    {
        prime[i] = i;
    }
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
ll cnt[1000001];
int main()
{
    faster();
    sieve();
    ll n, k;
    cin >> n >> k;
    for (ll i = 2; i <= n; i++)
        cnt[i]++;
    for (ll i = 2; i <= k; i++)
        cnt[i]--;
    for (ll i = 2; i <= n - k; i++)
        cnt[i]--;
    ll ans = 1;
    for (ll i = n; i > 1; i--)
    {
        if (prime[i] != i)
        {
            cnt[prime[i]] += cnt[i];
            cnt[i / prime[i]] += cnt[i];
            cnt[i] = 0;
        }
    }
    for (ll i = 2; i <= n; i++)
    {
        if (cnt[i])
            ans *= pow(i, cnt[i]);
    }
    cout << ans << endl;
}