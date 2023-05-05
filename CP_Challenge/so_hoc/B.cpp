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
ll a[1000001];
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll s = 0, pos;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            s += a[i];
            if (a[i] % 2 == 1)
            {
                pos = i;
            }
        }
        if (nto(s))
        {
            cout << n - 1 << endl;
            for (ll i = 1; i <= n; i++)
            {
                if (pos != i)
                    cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            cout << n << endl;
            for (ll i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
        }
        ms(a);
    }
}