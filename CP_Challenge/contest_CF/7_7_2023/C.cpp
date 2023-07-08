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
ll sum[1000001] = {0};
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    if (sum[a.first] != sum[b.first])
        return sum[a.first] < sum[b.first];
    return a.first < b.first;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        priority_queue<ll, vector<ll>, greater<ll>> qe;
        ll n, m, h;
        cin >> n >> m >> h;
        ll a[n][m];
        pair<ll, ll> b[n];
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
                qe.push(a[i][j]);
            }
            ll dem = 0;
            ll cnt = 0, res = 0;
            ll tam = 0;
            b[i].first = i;
            while (qe.size())
            {
                ll top = qe.top();
                qe.pop();
                dem += top;
                if (dem <= h)
                {
                    cnt++;
                    tam += top;
                    res = res + tam;
                    b[i].second = cnt;
                    sum[i] = res;
                }
                else
                    break;
            }
        }

        // cout << "TEST" << t << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << b[i].first << " " << b[i].second << " " << sum[b[i].first] << endl;
        // }

        ll res = 0;
        sort(b, b + n, cmp);
        for (ll i = 0; i < n; i++)
        {
            if (b[i].first == 0)
            {
                res = i + 1;
                break;
            }
        }
        cout << res << endl;
        ms(sum);
    }
}