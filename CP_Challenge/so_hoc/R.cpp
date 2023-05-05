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
ll n, m, f[maxn], cnt[maxn], ans = 1, a[maxn];
int main()
{
    faster();
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > m)
            continue;
        cnt[a[i]]++;
    }
    for (ll i = 1; i <= m; i++)
    {
        for (ll j = i; j <= m; j += i)
        {
            f[j] += cnt[i];
        }
    }
    for (ll i = 1; i <= m; i++)
    {
        if (f[i] > f[ans])
            ans = i;
    }
    cout << ans << " " << f[ans] << endl;
    for (ll i = 1; i <= n; i++)
        if (ans % a[i] == 0)
            cout << i << " ";
    cout << endl;
}