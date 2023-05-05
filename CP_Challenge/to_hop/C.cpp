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
ll pow_mod(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tam = pow_mod(a, b / 2);
    if (b & 1)
    {
        return tam * tam * a;
    }
    else
        return tam * tam;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll cnt[2] = {0};
        while (n--)
        {
            ll x;
            cin >> x;
            if (x == 1)
                cnt[1]++;
            else if (x == 0)
                cnt[0]++;
        }
        cout << cnt[1] * pow_mod(2, cnt[0]) << endl;
    }
}