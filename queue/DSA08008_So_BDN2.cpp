#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define maxn 1000006
#define _oo LLONG_MIN
#define oo (LLONG_MAX - 10009)
#define bit(x, i) ((x >> i) & 1)
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
vector<ll> v;
void init()
{
    queue<ll> qe;
    qe.push(1);
    while (true)
    {
        ll top = qe.front();
        qe.pop();
        if (top > pow(2, 62))
            break;
        v.push_back(top);
        qe.push(top * 10);
        qe.push(top * 10 + 1);
    }
}
int main()
{
    faster();
    init();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll cnt = 0;
        for (auto &x : v)
        {
            if (x % n == 0)
            {
                cout << x << endl;
                break;
            }
        }
    }
}