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
struct node
{
    ll s, t, cnt;
};
ll n, m, a[501][501], dem = 0;
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
bool check[501][501];
ll res = _oo;
void bfs()
{
    queue<node> qe;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (a[i][j] == 2 && !check[i][j])
            {
                qe.push({i, j, 0});
                check[i][j] = 1;
            }
        }
    }
    while (qe.size())
    {
        auto top = qe.front();
        qe.pop();
        res = max(res, top.cnt);
        for (ll i = 0; i < 4; i++)
        {
            ll xmoi = top.s + dx[i];
            ll ymoi = top.t + dy[i];
            if (!check[xmoi][ymoi] && xmoi >= 0 && xmoi < n && ymoi >= 0 && ymoi < m && a[xmoi][ymoi] == 1)
            {
                check[xmoi][ymoi] = true;
                qe.push({xmoi, ymoi, top.cnt + 1});
                dem--;
            }
        }
    }
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 1)
                    dem++;
            }
        }
        bfs();
        if (dem == 0)
            cout << res << endl;
        else
            cout << -1 << endl;
        ms(a);
        ms(check);
        res = _oo;
        dem = 0;
    }
}