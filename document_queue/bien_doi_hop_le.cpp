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
bool nto(ll n)
{
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return n > 1;
}
ll solve(ll s, ll t)
{
    set<ll> se;
    queue<pair<ll, ll>> qe;
    qe.push({s, 0});
    se.insert(s);
    while (!qe.empty())
    {
        auto top = qe.front();
        qe.pop();
        if (top.first == t)
            return top.second;
        string tam = to_string(top.first);
        for (ll i = 0; i < 4; i++)
        {
            char c = tam[i];
            for (char j = '0'; j <= '9'; j++)
            {
                if (tam[i] != (char)j)
                {
                    tam[i] = (char)j;
                    ll value = stoll(tam);
                    if (nto(value) && !se.count(value) && value >= 1000)
                    {
                        qe.push({value, top.second + 1});
                        se.insert(value);
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
        ll s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }
}