#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod1 = (ll)1e9 + 7;
#define endl "\n"
#define maxn 201
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
bool prime[maxn];
vector<ll> v;
void sieve()
{
    for (ll i = 2; i <= maxn - 1; i++)
        prime[i] = 1;
    for (ll i = 2; i <= sqrt(maxn - 1); i++)
    {
        if (prime[i] == 1)
            for (ll j = i * i; j <= maxn - 1; j += i)
                prime[j] = 0;
    }
    for (ll i = 2; i <= maxn - 1; i++)
        if (prime[i])
            v.push_back(i);
}
// ll mul(ll a, ll b, ll mod)
// {
//     a %= mod;
//     ll ans = 0;
//     while (b)
//     {
//         if (b & 1)
//         {
//             ans = ((ans % mod) + (a % mod)) % mod;
//         }
//         a = ((a % mod) + (a % mod)) % mod;
//         b /= 2;
//     }
//     return ans;
// }
// ll pow_mod(ll a, ll b, ll mod)
// {
//     a %= mod;
//     ll res = 1;
//     while (b)
//     {
//         if (b & 1)
//         {
//             res = mul(res, a, mod);
//         }
//         a = mul(a, a, mod);
//         b /= 2;
//     }
//     return res;
// }
// bool check(ll n, ll d)
// {
//     ll a = rand() % (n - 3) + 2;
//     ll x = pow_mod(a, d, n);
//     if (x == 1 || x == n - 1)
//         return 1;
//     while (d != n - 1)
//     {
//         x = mul(x, x, n);
//         if (x == n - 1)
//             return 1;
//         d *= 2;
//     }
//     return 0;
// }
// bool miler_rabin(ll n)
// {
//     if (n == 2 || n == 3)
//         return 1;
//     if (n < 5)
//         return 0;
//     if (n % 2 == 0 || n % 3 == 0)
//         return 0;
//     ll d = n - 1;
//     while (d % 2 == 0)
//     {
//         d = d / 2;
//     }
//     for (ll i = 1; i <= 10; i++)
//     {
//         if (check(n, d) == 0)
//             return 0;
//     }
//     return 1;
// }
// bool nto(ll n)
// {
//     if (n < 2)
//         return 0;
//     if (n == 2 || n == 3 || n == 5 || n == 7)
//         return 1;
//     if (n % 2 == 0 || n % 3 == 0)
//         return 0;
//     ll m = -1;
//     while (m * m <= n)
//     {
//         m += 6;
//         if (n % m == 0 || n % (m + 2) == 0)
//             return 0;
//     }
//     return 1;
// }
ll n, p, s;
vector<string> res, res2;
void back_track(vector<string> res, ll cnt, ll sum, ll pos)
{
    if (sum > s || cnt > n)
        return;
    for (ll i = pos; i < v.size(); i++)
    {
        if (v[i] > p)
        {
            if (cnt <= n && sum + v[i] <= s)
            {
                string tam = to_string(v[i]);
                res.push_back(tam);
                if (sum + v[i] == s && cnt == n)
                {
                    string tam = "";
                    for (auto x : res)
                    {
                        tam += x + " ";
                    }
                    tam.pop_back();
                    res2.push_back(tam);
                }
                else
                    back_track(res, cnt + 1, sum + v[i], i + 1);
                res.pop_back();
            }
        }
    }
}
int main()
{
    // faster();
    sieve();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> s;
        back_track(res, 1, 0, 0);
        cout << res2.size() << endl;
        for (auto &x : res2)
            cout << x << endl;
        res.clear();
        res2.clear();
    }
}