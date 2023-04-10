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
ll n, k, s, cnt = 0;
void back_track(ll i, ll begin, ll sum)
{
    for (ll j = begin; j <= n; j++)
    {
        if (sum + j <= s)
        {
            if (sum + j == s && i == k)
            {
                cnt++;
            }
            else
                back_track(i + 1, j + 1, sum + j);
        }
    }
}
int main()
{
    faster();
    cin >> n >> k >> s;
    back_track(1, 1, 0);
    cout << cnt << endl;
    return 0;
}