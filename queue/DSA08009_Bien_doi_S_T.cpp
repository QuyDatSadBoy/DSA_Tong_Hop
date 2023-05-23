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
ll bfs(ll n, ll m)
{
    set<ll> se;
    queue<pair<ll, ll>> qe;
    qe.push({n, 0});
    se.insert(n);
    while (qe.size())
    {
        auto top = qe.front();
        qe.pop();
        if (top.first == m)
            return top.second;
        if (top.first > 1 && !se.count(top.first - 1))
        {
            qe.push({top.first - 1, top.second + 1});
            se.insert(top.first - 1);
        }
        if (top.first * 2 <= 2 * m && !se.count(top.first * 2))
        {
            qe.push({top.first * 2, top.second + 1});
            se.insert(top.first * 2);
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
        ll n, m;
        cin >> n >> m;
        cout << bfs(n, m) << endl;
    }
}