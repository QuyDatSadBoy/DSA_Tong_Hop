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
        priority_queue<ll> f, s;
        for (auto &x : a)
        {
            cin >> x;
            f.push(x);
        }
        for (auto &x : b)
        {
            cin >> x;
            s.push(x);
        }
        ll ok = 0;
        while (!f.empty())
        {
            ll top1 = f.top();
            ll top2 = s.top();
            if (top1 == top2)
            {
                f.pop();
                s.pop();
            }
            else if (top1 > top2)
            {
                if (top1 / 2 == 0)
                {
                    ok = 1;
                    break;
                }
                f.pop();
                f.push(top1 / 2);
            }
            else
            {
                if (top2 > top1)
                {
                    if (top2 / 2 == 0)
                    {
                        ok = 1;
                        break;
                    }
                    s.pop();
                    s.push(top2 / 2);
                }
            }
        }
        if (ok == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}