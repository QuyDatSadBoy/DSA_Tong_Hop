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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n + 1];
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        ll i = n - 1;
        while (i >= 1 && a[i] > a[i + 1])
        {
            i--;
        }
        if (i == 0)
        {
            for (ll i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
        }
        else
        {
            ll j = n;
            while (a[j] <= a[i])
                j--;
            swap(a[i], a[j]);
            reverse(a + i + 1, a + n + 1);
            for (ll i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }
}