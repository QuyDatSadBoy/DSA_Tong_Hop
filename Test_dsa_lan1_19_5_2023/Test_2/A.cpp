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
    ll n, m;
    cin >> n >> m; // m la idex
    vector<string> v;
    ll a[n];
    for (ll i = 1; i <= n; i++)
    {
        a[i - 1] = i;
    }
    do
    {
        string res = "";
        for (ll i = 0; i < n; i++)
        {
            res += (a[i] + '0');
            res += ' ';
        }
        v.push_back(res);
    } while (next_permutation(a, a + n));
    for (ll i = 0; i < v.size(); i++)
    {
        if ((i + 1) % m == 0)
        {
            cout << v[i] << endl;
        }
    }
}