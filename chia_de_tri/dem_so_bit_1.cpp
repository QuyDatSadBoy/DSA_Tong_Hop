#include <bits/stdc++.h>
#define ll long long
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll bit_1(ll n, ll idex, ll area)
{
    ll res = (ll)pow(2, area);
    if (idex % 2 == 1)
        return 1;
    else
    {
        if (idex == res)
            return n % 2;
        else
        {
            if (idex > res)
                return bit_1(n / 2, res - (idex - res), area - 1);
            else
                return bit_1(n / 2, idex, area - 1);
        }
    }
}
int main()
{
    faster();
    ll n, l, r;
    cin >> n >> l >> r;
    ll ans = 0, area = (int)log2(n);
    for (ll i = l; i <= r; i++)
    {
        ans += bit_1(n, i, area);
    }
    cout << ans << endl;
    return 0;
}