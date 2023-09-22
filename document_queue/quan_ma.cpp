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
struct value
{
    ll x, y, w;
};
ll dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
ll dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
ll bfs(ll x, ll y, ll z, ll t)
{
    queue<value> qe;
    qe.push({x, y, 0});
    ll a[9][9];
    ms(a);
    a[x][y] = 1;
    while (!qe.empty())
    {
        value v = qe.front();
        qe.pop();
        if (v.x == z && v.y == t)
            return v.w;
        for (int i = 0; i < 8; i++)
        {
            ll nx = v.x + dx[i];
            ll ny = v.y + dy[i];
            if (nx >= 1 && nx < 9 && ny >= 1 && ny < 9 && a[nx][ny] == 0)
            {
                a[nx][ny] = 1;
                qe.push({nx, ny, v.w + 1});
            }
        }
    }
    return -1;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        char x, y;
        ll x1, y1;
        cin >> x >> x1 >> y >> y1;
        ll z = x - (ll)('a' - 1);
        ll k = y - (ll)('a' - 1);
        cout << bfs(z, x1, k, y1) << endl;
    }
}