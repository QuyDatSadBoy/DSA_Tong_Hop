#include <bits/stdc++.h>
#define ll long long
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
    ll T;
    cin >> T;
    while (T--)
    {
        ll s, t;
        cin >> s >> t;
        queue<pair<ll, ll>> qe;
        set<ll> se;
        qe.push({s, 0});
        se.insert(s);
        while (!qe.empty())
        {
            auto top = qe.front();
            qe.pop();
            if (top.first == t)
            {
                cout << top.second << endl;
                break;
            }
            if (!se.count(top.first * 2) && top.first < t)
            {
                qe.push({top.first * 2, top.second + 1});
                se.insert(top.first * 2);
            }
            if (top.first > 1 && !se.count(top.first - 1))
            {
                qe.push({top.first - 1, top.second + 1});
                se.insert(top.first - 1);
            }
        }
    }
}