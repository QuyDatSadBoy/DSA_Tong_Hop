#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"
ll ans = 0;
void solve(pair<ll, ll> a[], ll l, ll r)
{
    sort(a + l, a + r + 1, [](pair<ll, ll> a, pair<ll, ll> b) -> bool
         {
		if(a.first!=b.first) return a.first<b.first;
		return a.second>b.second; });
    for (ll i = l + 1; i <= r; i++)
    {
        for (ll j = l; j < i; j++)
        {
            if (a[j].second < a[i].second)
                ans++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        pair<ll, ll> a[n * m + 1];
        for (ll i = 1; i <= n * m; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a + 1, a + n * m + 1);
        for (ll i = 1; i <= n * m; i += m)
        {
            solve(a, i, i + m - 1);
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}