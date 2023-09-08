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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    if (n == 2)
    {
        if (a[0] == a[1])
            cout << a[0] + 1 << endl;
        else
            cout << a[1] << endl;
    }
    else
    {
        vector<ll> res;
        while (true)
        {
            ll ok = 0, ok2 = 0;
            for (ll i = 0; i < a.size() - 1; i++)
            {
                if (a[i] == a[i + 1])
                {
                    if (i == a.size() - 2)
                    {
                        res.push_back(a[i] + 1);
                        i++;
                        ok2 = 1;
                    }
                    else
                    {
                        if (a[i + 1] < a[i + 2])
                        {
                            res.push_back(a[i] + 1);
                            i++;
                            ok = 1;
                        }
                        else
                            res.push_back(a[i]);
                    }
                }
                else
                    res.push_back(a[i]);
            }
            // cout << "res=" << endl;
            // for (auto x : res)
            //     cout << x << " ";
            // cout << endl;
            if (!ok2)
                res.push_back(a.back());
            if (!ok && !ok2)
                break;
            a.clear();
            a = vector<ll>(res.begin(), res.end());
            // cout << "a=" << endl;
            // for (auto x : a)
            //     cout << x << " ";
            // cout << endl;
            res.clear();
        }
        cout << res.back() << endl;
    }
}