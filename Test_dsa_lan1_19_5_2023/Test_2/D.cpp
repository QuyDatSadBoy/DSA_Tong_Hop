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
    map<string, ll> mp;
    map<string, vector<string>> adj;
    ll t;
    cin >> t;
    cin.ignore(1);
    while (t--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        if (!mp[a] || !mp[c])
        {
            if (b == ">")
            {
                mp[a] = 2;
                mp[c] = 1;
                adj[c].push_back(a);
                if (adj[a].size())
                {
                    mp[a] = mp[adj[a].front()];
                    for (auto x : adj[a])
                    {
                        mp[x]++;
                        if (adj[x].size())
                        {
                            mp[x] = mp[adj[x].front()];
                            for (auto y : adj[x])
                                mp[y]++;
                        }
                    }
                }
            }
            else
            {
                mp[a] = 1;
                mp[c] = 2;
                adj[a].push_back(c);
                if (adj[c].size())
                {
                    mp[c] = mp[adj[c].front()];
                    for (auto x : adj[c])
                    {
                        mp[x]++;
                        if (adj[x].size())
                        {
                            mp[x] = mp[adj[x].front()];
                            for (auto y : adj[x])
                                mp[y]++;
                        }
                    }
                }
            }
        }
        else
        {
            if (b == ">")
            {
                if (mp[a] <= mp[b])
                {
                    cout << "impossible" << endl;
                    return 0;
                }
            }
            else
            {
                if (mp[a] >= mp[b])
                {
                    cout << "impossible" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "possible" << endl;
}