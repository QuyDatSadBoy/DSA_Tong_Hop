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
ll t[maxn], n, q;
ll get(ll x)
{
    int ans = 0;
    while (x)
    {
        ans += t[x];
        x -= x & (-x);
    }
    return ans;
}
void update(ll x)
{
    while (x <= n)
    {
        t[x]++;
        x += x & (-x);
    }
}
int main()
{
    faster();
    cin >> q >> n;
    while (q--)
    {
        ll t, x;
        cin >> t >> x;
        if (t == 1)
        {
            update(x);
        }
        else
            cout << get(x) << endl;
    }
}