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
    ll n, m;
    cin >> n >> m;
    ll a[n], b[m];
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    ll res = 0, i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] > b[j])
        {
            i++;
            j++;
            res++;
        }
        else
        {
            i++;
        }
    }
    cout << res << endl;
}