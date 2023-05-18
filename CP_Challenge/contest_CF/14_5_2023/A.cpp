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
ll lcm(ll i, ll n)
{
    ll res = 1;
    for (ll j = 1; j <= i; j++)
    {
        res = __gcd(res * j, n);
    }
    return n / res * i;
}
int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        int tong = 0;
        a[n] = n;
        for (int i = 1; i <= n - 1; i++)
            a[i] = i;
        if ((n - 1) % 2 == 1)
        {
            int i = 1;
            while (((n / 2) * i) % n != 0 || (n / 2) * i <= 200)
                i++;
            a[n / 2] = n / 2 * i;
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}