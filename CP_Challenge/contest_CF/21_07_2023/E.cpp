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
    ll Test;
    cin >> Test;
    while (Test--)
    {
        ll n, k;
        cin >> n >> k;
        long long d[n + 1] = {0}, sum = 0, sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
            sum += d[i];
            sum1 += d[i] * d[i];
        }
        ll cd = (sum1 - k) / n;
        ll a = 1;
        ll b = (2 * sum) / n;
        ll denta_oke = sqrt(b * b - 4 * a * cd);
        ll x1 = (-b + denta_oke) / (2 * a);
        cout << x1 / 2 << endl;
    }
    return 0;
}
