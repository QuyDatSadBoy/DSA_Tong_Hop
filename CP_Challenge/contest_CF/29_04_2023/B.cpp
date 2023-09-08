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
        ll a[n + 1] = {0};
        ll sum = (n + 1) * (n) / 2;
        if (sum % n != 0 || sum == 1)
        {
            for (ll i = 1; i <= n; i++)
            {
                a[i] = i;
            }
            for (ll i = 1; i <= n - 1; i += 2)
                swap(a[i], a[i + 1]);
            for (ll i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
}