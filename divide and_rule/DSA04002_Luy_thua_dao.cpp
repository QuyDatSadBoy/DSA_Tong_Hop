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
ll pow_mod(ll a, ll b, ll mod)
{
    if (b == 1)
        return a % mod;
    ll res = pow_mod(a, b / 2, mod) % mod;
    res = (res * res) % mod;
    if (b & 1)
        res = (res * a) % mod;
    return res;
}
int main()
{
    faster();
    int test = 1;
    cin >> test;
    cin.ignore();
    while (test--)
    {
        string s;
        cin >> s;
        string tam = s;
        reverse(all(s));
        cout << pow_mod(stoll(tam), stoll(s), mod) << endl;
    }
}