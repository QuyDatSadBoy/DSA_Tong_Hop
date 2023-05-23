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
ll n, u, v, s, t;
char a[101][101];
bool check[101][101];
ll bfs()
{
    queue<pair<pair<ll, ll>, ll>> qe;
    qe.push({{u, v}, 0});
    check[u][v] = 1;
    while (qe.size())
    {
        auto top = qe.front();
        qe.pop();
        ll x = top.first.first;
        ll y = top.first.second;
        if (x == s && y == t)
        {
            return top.second;
        }
        for (ll i = x + 1; i < n; i++)
        {
            if (!check[i][y] && a[i][y] != 'X')
            {
                qe.push({{i, y}, top.second + 1});
                check[i][y] = 1;
            }
            else
                break;
        }
        for (ll i = x - 1; i >= 0; i--)
        {
            if (!check[i][y] && a[i][y] != 'X')
            {
                qe.push({{i, y}, top.second + 1});
                check[i][y] = 1;
            }
            else
                break;
        }
        for (ll i = y + 1; i < n; i++)
        {
            if (!check[x][i] && a[x][i] != 'X')
            {
                qe.push({{x, i}, top.second + 1});
                check[x][i] = 1;
            }
            else
                break;
        }
        for (ll i = y - 1; i >= 0; i--)
        {
            if (!check[x][i] && a[x][i] != 'X')
            {
                qe.push({{x, i}, top.second + 1});
                check[x][i] = 1;
            }
            else
                break;
        }
    }
    return -1;
}
int main()
{
    faster();
    ll T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
                cin >> a[i][j];
        }
        cin >> u >> v >> s >> t;
        cout << bfs() << endl;
        ms(check);
    }
}