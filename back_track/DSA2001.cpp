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
ll n, a[maxn];
void init()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}
void back_track(ll i)
{
    if (i < 1)
        return;
    cout << "[";
    for (ll j = 1; j <= i; j++)
    {
        cout << a[j];
        if (j == i)
            cout << "]";
        else
            cout << " ";
    }
    cout << endl;
    for (ll j = 1; j <= i - 1; j++)
    {
        a[j] += a[j + 1];
    }
    back_track(i - 1);
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        init();
        back_track(n);
        ms(a);
    }
    return 0;
}