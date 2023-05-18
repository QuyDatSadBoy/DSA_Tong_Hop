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
char answer(ll n, ll k)
{
    if (k % 2 == 1)
        return 'A';
    ll pos = pow(2, n - 1);
    if (k == pos)
        return ('A' + (n - 1));
    else
    {
        if (k < pos)
            return answer(n - 1, k);
        else
            return answer(n - 1, k - pos);
    }
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << answer(n, k) << endl;
    }
}