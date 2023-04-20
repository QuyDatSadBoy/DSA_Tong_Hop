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
    ll res = 0, i = 0, j = n - 1;
    sort(a, a + n);
    while (i < j && j >= 0)
    {
        if (a[i] + a[j] <= x)
        {
            res++;
            i++;
            j--;
        }
        else
        {
            res++;
            j--;
        }
    }
    if (i == j)
        res++;
    cout << res << endl;
}