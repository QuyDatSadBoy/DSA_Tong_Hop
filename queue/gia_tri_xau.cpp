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
        ll k;
        cin >> k;
        cin.ignore();
        string s;
        cin >> s;
        ll ans = 0;
        map<char, ll> mp;
        for (auto x : s)
            mp[x]++;
        priority_queue<ll> qe;
        for (auto it : mp)
        {
            qe.push(it.second);
        }
        while (k--)
        {
            ll top = qe.top();
            qe.pop();
            qe.push(max(1ll * 0, top - 1));
        }
        while (!qe.empty())
        {
            ans += (ll)pow(qe.top(), 2);
            qe.pop();
        }
        cout << ans << endl;
    }
}