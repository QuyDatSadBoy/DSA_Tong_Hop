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

int main()
{
    faster();
    vector<ll> v;
    map<ll, bool> mp;
    priority_queue<ll, vector<ll>, greater<ll>> qe;
    qe.push(1);
    while (v.size() < (ll)(1e4))
    {
        ll tam = qe.top();
        qe.pop();
        v.push_back(tam);
        if (!mp[tam * 2])
        {
            qe.push(tam * 2);
            mp[tam * 2] = 1;
        }
        if (!mp[tam * 3])
        {
            qe.push(tam * 3);
            mp[tam * 3] = 1;
        }
        if (!mp[tam * 5])
        {
            qe.push(tam * 5);
            mp[tam * 5] = 1;
        }
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << v[n - 1] << endl;
    }
}