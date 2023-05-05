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
bool nto(ll n)
{
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return n > 1;
}
ll prime[1000001] = {0};
void sieve()
{
    for (ll i = 0; i <= 1000000; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (ll i = 2; i <= sqrt(1000000); i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= 1000000; j += i)
            {
                prime[j] = 0;
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
    ll a[n];
    for (auto &x : a)
    {
        cin >> x;
        ll tam = sqrt(x);
        if (tam * tam == x)
        {
            if (prime[tam])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }
}