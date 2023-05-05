#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
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
    ll n, x;
    cin >> n >> x;
    if (x == 1)
        cout << 1 << endl;
    else
    {
        ll ans = 0;
        for (ll i = 1; i * i <= x; i++)
        {
            if (i * i != x)
            {
                if (x % i == 0)
                {
                    if (i <= n && x / i <= n)
                        ans += 2;
                }
            }
            else
            {
                if (x % i == 0 && i <= n)
                    ans++;
            }
        }
        cout << ans << endl;
    }
}