#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
const ll mod = (ll)1e9 + 7;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define ms(a) memset(a, 0, sizeof(a))
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
ll count(ll s)
{
    string tam = to_string(s);
    return tam.size();
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n], b[n];
        priority_queue<ll> c, d;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            c.push(a[i]);
        }
        for (auto &x : b)
        {
            cin >> x;
            d.push(x);
        }
        ll cnt = 0;
        while (!c.empty())
        {
            ll top1 = c.top();
            ll top2 = d.top();
            c.pop();
            d.pop();
            if (top1 == top2)
                continue;
            if (top1 > top2)
            {
                cnt++;
                c.push(count(top1));
                d.push(top2);
            }
            if (top1 < top2)
            {
                cnt++;
                c.push(top1);
                d.push(count(top2));
            }
        }
        cout << cnt << endl;
    }
}