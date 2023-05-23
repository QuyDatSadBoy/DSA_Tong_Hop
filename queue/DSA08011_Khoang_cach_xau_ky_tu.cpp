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
set<string> se;
ll bfs(string a, string b)
{
    queue<pair<string, ll>> qe;
    qe.push({a, 1});
    while (qe.size())
    {
        auto top = qe.front();
        qe.pop();
        string tam = top.first;
        if (tam == b)
            return top.second;
        for (ll i = 0; i < tam.size(); i++)
        {
            char c = tam[i];
            for (char j = 'A'; j <= 'Z'; j++)
            {
                if (tam[i] != j)
                {
                    tam[i] = j;
                    if (se.count(tam))
                    {
                        qe.push({tam, top.second + 1});
                        se.erase(tam);
                    }
                }
            }
            tam[i] = c;
        }
    }
    return -1;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        string s, t;
        cin >> n >> s >> t;
        while (n--)
        {
            string tam;
            cin >> tam;
            if (tam != s)
                se.insert(tam);
        }
        cout << bfs(s, t) << endl;
        se.clear();
    }
}