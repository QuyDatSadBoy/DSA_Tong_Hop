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
ll n, a[1000001];
priority_queue<pair<ll, ll>> qe;
set<pair<ll, ll>> se;
int ans = 0;
int main()
{
    faster();
    ll cnt = 1;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 2; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            qe.push({cnt, -(i - 1)});
            se.insert({i - 1, cnt});
            cnt = 1;
        }
        else
            cnt++;
    }
    qe.push({cnt, -n});
    se.insert({n, cnt});
    while (qe.size())
    {
        ll cnt = qe.top().first;
        ll pos = -(qe.top().second);
        qe.pop();
        auto it = se.lower_bound({pos, cnt});
        if (it != se.end() && *it == make_pair(pos, cnt))
        {
            ++ans;
            auto nxt = next(it);
            auto pre = prev(it);
            if (nxt != se.end() && it != se.begin())
            {
                if (a[nxt->first] == a[pre->first])
                {
                    ll new_pos = pre->first;
                    ll new_cnt = pre->second + nxt->second;
                    se.erase(pre);
                    se.erase(nxt);
                    se.insert({new_pos, new_cnt});
                    qe.push({new_cnt, -new_pos});
                }
            }
            se.erase(it);
        }
    }
    cout << ans << endl;
}