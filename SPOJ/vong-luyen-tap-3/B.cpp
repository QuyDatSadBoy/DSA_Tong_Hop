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

int main()
{
    faster();
    ll n, k;
    cin >> n >> k;
    ll res = 0, ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        string s = to_string(i);
        for (ll j = 0; j < s.length(); j++)
        {
            ans = (ans * 10 + (s[j] - '0')) % k;
        }
        if (ans == 0)
        {
            res++;
            // cout << "n=" << i << endl;
        }
    }
    cout << res << endl;
}