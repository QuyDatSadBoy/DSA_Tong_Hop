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
ll solve(ll n, ll m)
{
    queue<ll> qe;
    qe.push(n);
    while (!qe.empty())
    {
        ll top = qe.front();
        qe.pop();
        if (top == m)
            return 1;
        if (top % 3 == 0)
        {
            ll tam = top / 3;
            qe.push(tam);
            qe.push(tam * 2);
        }
    }
    return 0;
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
        if (solve(n, m))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}