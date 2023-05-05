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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (auto &x : a)
            cin >> x;
        ll i = 0, j = n - 1, ans = 0, s1 = 0, s2 = 0;
        while (i <= j)
        {
            s1 += a[i++];
            while (s2 < s1 && j >= i)
                s2 += a[j--];
            if (s1 == s2)
                ans = max(ans, i + n - j - 1);
        }
        cout << ans << endl;
    }
}