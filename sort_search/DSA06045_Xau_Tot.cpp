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
    ll n;
    cin >> n;
    cin.ignore(1);
    string s;
    cin >> s;
    ll cnt = 1, res = n * (n - 1) >> 1;
    vector<ll> v;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            cnt++;
        else
        {
            v.push_back(cnt);
            cnt = 1;
        }
    }
    v.push_back(cnt);
    for (ll i = 1; i < v.size(); i++)
    {
        res -= (v[i] + v[i - 1] - 1);
    }
    cout << res << endl;
}