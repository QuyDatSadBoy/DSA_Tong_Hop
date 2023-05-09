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
char c;
ll k, n;
void back_track(ll i, string res, ll pos)
{
    for (ll j = pos; j <= n; j++)
    {
        res += ('A' + j);
        if (i == k)
            cout << res << endl;
        else
            back_track(i + 1, res, j);
        res.pop_back();
    }
}
int main()
{
    faster();
    cin >> c >> k;
    n = c - 'A';
    back_track(1, "", 0);
}