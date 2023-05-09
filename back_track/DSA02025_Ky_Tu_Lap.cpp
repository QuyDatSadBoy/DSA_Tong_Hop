#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define _oo LLONG_MIN
#define oo LLONG_MAX - 9
#define bit(x, i) ((x >> i) & 1)
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
string v[11];
ll n, a[11], visited[11], res = 0, ans = oo;
ll different(string s, string t)
{
    ll cnt[26] = {0}, dem = 0;
    for (auto &x : s)
        cnt[x - 'A'] = 1;
    for (auto &x : t)
        if (cnt[x - 'A'])
            dem++;
    return dem;
}
void Min(ll i)
{
    for (ll j = 1; j <= n; j++)
    {
        if (!visited[j])
        {
            a[i] = j;
            visited[j] = true;
            res += different(v[j], v[a[i - 1]]);
            if (i == n)
            {
                if (res < ans)
                    ans = res;
            }
            else if (res < ans)
                Min(i + 1);
            visited[j] = 0;
            res -= different(v[j], v[a[i - 1]]);
        }
    }
}
int main()
{
    // faster();
    cin >> n;
    v[0] = "";
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    Min(1);
    cout << ans << endl;
}