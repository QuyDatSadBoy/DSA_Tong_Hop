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
ll res = (int)1e9;
void back_track(ll n, ll cnt)
{
    if (cnt >= res)
        return;
    if (n == 1)
    {
        res = min(res, cnt);
        return;
    }
    if (n % 2 == 0)
    {
        back_track(n / 2, cnt + 1);
    }
    if (n % 3 == 0)
    {
        back_track(n / 3, cnt + 1);
    }
    if (n > 1)
    {
        back_track(n - 1, cnt + 1);
    }
}
int main()
{
    faster();
    ll n;
    cin >> n;
    back_track(n, 0);
    cout << res << endl;
}