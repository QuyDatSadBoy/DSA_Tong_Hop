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
ll dx[] = {1, -1, 0, 0, 0, 0};
ll dy[] = {0, 0, 1, -1, 0, 0};
ll dz[] = {0, 0, 0, 0, 1, -1};
struct node
{
    ll a1, b1, c1;
};
char f[31][31][31];
bool visited[31][31][31];
ll a, b, c;
bool check(ll i, ll j, ll k)
{
    if (i >= 0 && j >= 0 && k >= 0 && i < a && j < b && k < c && f[i][j][k] != '#')
    {
        return true;
    }
    return false;
}
ll bfs(ll i, ll j, ll k)
{
    queue<pair<node, ll>> qe;
    qe.push({{i, j, k}, 0});
    f[i][j][k] = '#';
    while (qe.size())
    {
        auto top = qe.front();
        qe.pop();
        ll x = top.first.a1;
        ll y = top.first.b1;
        ll z = top.first.c1;
        if (f[x][y][z] == 'E')
            return top.second;
        for (ll h = 0; h < 6; h++)
        {
            if (check(x + dx[h], y + dy[h], z + dz[h]))
            {
                if (f[x + dx[h]][y + dy[h]][z + dz[h]] == 'E')
                    return top.second + 1;
                qe.push({{x + dx[h], y + dy[h], z + dz[h]}, top.second + 1});
                f[x + dx[h]][y + dy[h]][z + dz[h]] = '#';
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
        cin >> a >> b >> c;
        vector<ll> v;
        for (ll i = 0; i < a; i++)
        {
            for (ll j = 0; j < b; j++)
            {
                for (ll k = 0; k < c; k++)
                {
                    cin >> f[i][j][k];
                    if (f[i][j][k] == 'S')
                    {
                        v.push_back(i);
                        v.push_back(j);
                        v.push_back(k);
                    }
                }
            }
        }
        cout << bfs(v[0], v[1], v[2]) << endl;
    }
}