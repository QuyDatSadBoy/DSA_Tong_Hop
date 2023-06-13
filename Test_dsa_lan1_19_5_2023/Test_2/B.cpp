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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    priority_queue<ll, vector<ll>, greater<ll>> qe;
    ll sum = 0, ans = 0;
    for (auto &x : a)
    {
        cin >> x;
        sum += x;
        qe.push(x);
    }
    while (qe.size() > 1)
    {
        if (qe.size() < k)
        {
            ll res = 0;
            ll Min1 = qe.top();
            ll Min2;
            while (qe.size())
            {
                Min2 = qe.top();
                res += qe.top();
                qe.pop();
            }
            qe.push(res);
            ans += Min2 - Min1;
            break;
        }
        else
        {
            for (ll i = 1; i <= k; i++)
            {
                ll res = 0;
                ll Min1 = qe.top();
                ll Min2;
                ll cnt = 0;
                while (qe.size())
                {
                    if (cnt == k)
                        break;
                    Min2 = qe.top();
                    res += qe.top();
                    qe.pop();
                    cnt++;
                }
                ans += Min2 - Min1;
                qe.push(res);
            }
        }
    }
    cout << qe.top() << endl;
    cout << ans << endl;
}