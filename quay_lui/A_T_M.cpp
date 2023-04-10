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
ll n, s, res = (int)1e9, a[1000001], ok = 0;
void back_track(ll sum, ll cnt, ll begin)
{
    for (ll i = begin; i < n; i++)
    {
        if (sum + a[i] <= s)
        {
            if (sum + a[i] == s)
            {
                res = min(res, cnt);
                ok = 1;
            }
            else
            {
                back_track(sum + a[i], cnt + 1, i + 1);
            }
        }
    }
}
int main()
{
    faster();
    cin >> n >> s;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    back_track(0, 1, 0);
    if (!ok)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << res << endl;
    }
}