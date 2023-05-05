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
map<string, pair<string, ll>> mp;
ll count(string s)
{
    ll cnt = 0;
    for (ll i = 0; i + 3 < s.size(); i++)
    {
        cnt += s.substr(i, 4) == "haha";
    }
    return cnt;
}
pair<string, ll> Merge(pair<string, ll> a, pair<string, ll> b)
{
    ll cnt = a.second + b.second;
    string s = a.first + b.first;
    for (ll i = max((long long)0, (ll)a.first.size() - 3); i < a.first.size(); i++)
    {
        cnt += s.substr(i, 4) == "haha";
    }
    if (s.size() > 6)
        s.erase(s.begin() + 3, s.end() - 3);
    return {s, cnt};
}
int main()
{
    faster();
    ll t;
    cin >> t;
    cin.ignore(1);
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            string var, op;
            cin >> var >> op;
            if (op == ":=")
            {
                string s;
                cin >> s;
                mp[var] = {s, count(s)};
            }
            else
            {
                string a, b;
                cin >> a >> b >> b;
                mp[var] = Merge(mp[a], mp[b]);
            }
            if (i == n)
                cout << mp[var].second << endl;
        }
    }
}