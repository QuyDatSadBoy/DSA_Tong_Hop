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
ll n, x[1000001], m, a[1000001];
map<ll, ll> mp;
void back_track(ll i)
{
    for (ll j = 1; j <= 4; j++)
    {
        x[i] = a[j];
        mp[x[i]]++;
        if (i == m)
        {
            if (mp[2] > 0 && mp[3] > 0 && mp[5] > 0 && mp[7] > 0 && x[m] != 2)
            {
                for (ll k = 1; k <= m; k++)
                {
                    cout << x[k];
                }
                cout << endl;
            }
        }
        else
            back_track(i + 1);
        mp[x[i]]--;
    }
}
int main()
{
    faster();
    a[1] = 2;
    a[2] = 3;
    a[3] = 5;
    a[4] = 7;
    cin >> n;
    for (ll i = 4; i <= n; i++)
    {
        m = i;
        back_track(1);
    }
}