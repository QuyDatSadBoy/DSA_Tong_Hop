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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        unordered_map<ll, ll> mp;
        queue<pair<ll, ll>> qe;
        qe.push({n, 0});
        mp[n] = 1;
        while (1)
        {
            auto top = qe.front();
            qe.pop();
            if (top.first == 1)
            {
                cout << top.second << endl;
                break;
            }
            for (ll i = 2; i <= sqrt(top.first); i++)
            {
                if (top.first % i == 0)
                {
                    ll ans = max(i, top.first / i);
                    if (mp[ans] == 0)
                    {
                        qe.push({ans, top.second + 1});
                        mp[ans] = 1;
                    }
                }
            }
            if (mp[top.first - 1] == 0)
            {
                qe.push({top.first - 1, top.second + 1});
                mp[top.first - 1] = 1;
            }
        }
    }
}