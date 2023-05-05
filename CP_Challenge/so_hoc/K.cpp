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
    ll a, b;
    cin >> a >> b;
    if (a == b)
        cout << "infinity" << endl;
    else
    {
        if (a < b)
            cout << 0 << endl;
        else
        {
            ll ans = 0;
            ll sub = a - b;
            for (ll i = 1; i <= sqrt(sub); i++)
            {
                if (sub % i == 0)
                {
                    ans += i > b;
                    if (i * i != sub)
                        ans += (sub / i) > b;
                }
            }
            cout << ans << endl;
        }
    }
}