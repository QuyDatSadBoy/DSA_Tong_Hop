#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll res = 1;
        if (n % 2 == 1)
            cout << 0 << endl;
        else
        {
            for (ll i = 1; i <= n / 2; i++)
            {
                res *= i;
                res %= 998244353;
            }
            res = res % 998244353 * (res % 998244353) % 998244353;
            cout << res << endl;
        }
    }
}