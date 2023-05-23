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
vector<ll> v;
void init()
{
    queue<ll> qe;
    qe.push(1);
    qe.push(2);
    qe.push(3);
    qe.push(4);
    qe.push(5);
    while (qe.size())
    {
        ll top = qe.front();
        qe.pop();
        if (top > 1e5)
            break;
        v.push_back(top);
        ll mp[6] = {0};
        ll tam = top;
        while (tam)
        {
            ll r = tam % 10;
            mp[r] = 1;
            tam /= 10;
        }
        for (ll i = 0; i < 6; i++)
        {
            if (mp[i] == 0)
            {
                qe.push(top * 10 + i);
            }
        }
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
        ll n, m;
        cin >> n >> m;
        ll cnt = 0;
        for (auto &x : v)
        {
            if (x >= n && x <= m)
                cnt++;
            else if (x > m)
                break;
        }
        cout << cnt << endl;
    }
}