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
    ll a[n];
    for (auto &x : a)
        cin >> x;
    sort(a, a + n);
    bool ok = false;
    for (ll i = 0; i < n; i++)
    {
        if (binary_search(a + i + 1, a + n, x + a[i]))
        {
            ok = true;
            break;
        }
    }
    if (ok)
        cout << 1 << endl;
    else
        cout << -1 << endl;
}