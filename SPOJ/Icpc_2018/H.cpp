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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        queue<ll> qe;
        vector<ll> res;
        ll Max = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            Max = max(x, Max);
            qe.push(x);
        }
        res.push_back(Max);
        while (qe.size() > 1)
        {
            Max = 0;
            vector<ll> tam;
            ll pre = qe.front();
            qe.pop();
            while (qe.size())
            {
                ll top = qe.front();
                qe.pop();
                Max = max(Max, min(pre, top));
                tam.push_back(min(pre, top));
                pre = top;
            }
            // cout << "tam = " << endl;
            // for (auto x : tam)
            //     cout << x << " ";
            // cout << endl;
            res.push_back(Max);
            for (ll i = 0; i < tam.size(); i++)
            {
                qe.push(tam[i]);
            }
        }
        for (auto x : res)
            cout << x << " ";
        cout << endl;
    }
}