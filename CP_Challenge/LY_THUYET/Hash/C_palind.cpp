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
ll Hash[maxn], Pow[maxn], Hash2[maxn];
ll getHash(ll l, ll r)
{
    return ((Hash[r] - Hash[l - 1] * Pow[r - l + 1]) % mod + mod) % mod;
}
ll getHash2(ll l, ll r)
{
    return ((Hash2[r] - Hash2[l - 1] * Pow[r - l + 1]) % mod + mod) % mod;
}
int main()
{
    // Mỗi test kiểm tra xem đoạn từ l đến r có đối xứng hay không
    faster();
    Pow[0] = 1;
    string s;
    cin >> s;
    string t = s;
    reverse(all(t));
    ll n = s.size();
    s = ' ' + s;
    t = ' ' + t;
    for (ll i = 1; i <= n; i++)
    {
        Hash[i] = (Hash[i - 1] * 31 + s[i] - 'a' + 1) % mod;
        Pow[i] = Pow[i - 1] * 31 % mod;
    }
    Pow[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        Hash2[i] = (Hash2[i - 1] * 31 + t[i] - 'a' + 1) % mod;
        Pow[i] = Pow[i - 1] * 31 % mod;
    }
    ll T;
    cin >> T;
    while (T--)
    {
        ll l, r;
        cin >> l >> r;
        if (getHash(l, r) == getHash2(n - r + 1, n - l + 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}