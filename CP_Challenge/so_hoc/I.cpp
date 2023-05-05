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
ll nto(ll n)
{
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return n > 1;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (nto(n))
        {
            cout << 1 << endl
                 << n << endl;
        }
        else
        {
            ll ans, res = 0, cnt = 0;
            ll m = n;
            for (ll i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    cnt = 0;
                    while (n % i == 0)
                    {
                        cnt++;
                        n /= i;
                    }
                    if (cnt > res)
                    {
                        res = cnt;
                        ans = i;
                    }
                }
            }
            cnt = 0;
            if (n != 1)
                cnt++;
            if (cnt > res)
            {
                res = cnt;
                ans = n;
            }
            cout << res << endl;
            for (ll i = 1; i < res; i++)
            {
                cout << ans << " ";
                m /= ans;
            }
            cout << m << endl;
        }
    }
}