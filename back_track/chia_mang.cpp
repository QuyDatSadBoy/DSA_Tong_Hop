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
ll n, k, s, ok = 0, ans = 0, a[1000001], visited[1000001];
void back_track(ll sum, ll ans)
{
    if (ans == k)
    {
        ok++;
    }
    for (ll i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            if (sum + a[i] <= s)
            {
                if (sum + a[i] == s)
                {
                    back_track(0, ans + 1);
                }
                else
                {
                    back_track(sum + a[i], ans);
                }
            }
            visited[i] = 0;
        }
    }
}
int main()
{
    faster();
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % k != 0)
        cout << 0 << endl;
    else
    {
        s /= k;
        back_track(0, 0);
        cout << ok << endl;
    }
}