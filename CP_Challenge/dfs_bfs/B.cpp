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
ll solve(ll n, ll m)
{
    set<ll> se;
    queue<pair<ll, ll>> qe;
    qe.push({n, 0});
    se.insert(n);
    while (!qe.empty())
    {
        auto top = qe.front();
        qe.pop();
        ll dinh = top.first;
        ll cnt = top.second;
        if (dinh == m)
            return cnt;
        if (dinh > 1 && se.count(dinh - 1) == 0)
        {
            se.insert(dinh - 1);
            qe.push({dinh - 1, cnt + 1});
        }
        if (dinh < m && se.count(dinh * 2) == 0)
        {
            se.insert(dinh * 2);
            qe.push({dinh * 2, cnt + 1});
        }
    }
    return -1;
}
int main()
{
    faster();
    ll n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
}