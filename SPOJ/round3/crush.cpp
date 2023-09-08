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

const ll MAX_N = 10000001; // Đặt giới hạn cho số lượng số trong chuỗi

vector<bool> prime(MAX_N, true);

void sieve()
{
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i < MAX_N; ++i)
    {
        if (prime[i])
        {
            for (ll j = i * i; j < MAX_N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    faster();
    sieve();
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    vector<ll> f(n + 1, 0);
    for (ll i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] + (prime[a[i]] ? 1 : 0);
    }

    ll count = 0;
    for (ll l = 1; l <= n; ++l)
    {
        for (ll r = l; r <= n; ++r)
        {
            ll cnt = f[r] - f[l - 1];
            ll tam = (r - l + 1) - cnt;
            if (cnt >= tam)
            {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}