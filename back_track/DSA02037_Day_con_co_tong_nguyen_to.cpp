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
bool nto(int n)
{
    if (n < 2)
        return 0;
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    ll m = -1;
    while (m * m <= n)
    {
        m += 6;
        if (n % m == 0 || n % (m + 2) == 0)
            return 0;
    }
    return 1;
}
int n, a[16], b[16];
vector<vector<int>> v;
int sum = 0;
void back_track(int i, int pos)
{
    if (i <= n - 1)
    {
        for (int j = pos; j < n; ++j)
        {
            b[i] = a[j];
            sum += b[i];
            if (nto(sum) == 1)
            {
                vector<int> tam;
                for (int k = 0; k <= i; ++k)
                    tam.push_back(b[k]);
                v.push_back(tam);
            }
            back_track(i + 1, j + 1);
            sum -= b[i];
        }
    }
}

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, greater<ll>());
        back_track(0, 0);
        sort(all(v));
        for (auto &x : v)
        {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }
        sum = 0;
        v.clear();
    }
    return 0;
}