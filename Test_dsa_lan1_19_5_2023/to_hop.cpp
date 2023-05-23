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
string s;
ll k;
set<ll> se2;
void back_track(vector<ll> v, vector<ll> res, ll i, ll pos)
{
    for (ll j = pos; j < v.size(); j++)
    {
        res.push_back(v[j]);
        if (i == k)
        {
            ll sum = 0;
            for (auto x : res)
            {
                sum = sum * 10 + x;
            }
            se2.insert(sum);
        }
        else
            back_track(v, res, i + 1, j + 1);
        res.pop_back();
    }
}
int main()
{
    faster();
    ll t;
    cin >> t;
    cin.ignore(1);
    while (t--)
    {
        cin >> s >> k;
        vector<ll> v;
        vector<ll> res;
        for (auto x : s)
        {
            v.push_back(x - '0');
        }
        back_track(v, res, 1, 0);
        for (auto x : se2)
            cout << x << endl;
        se2.clear();
    }
}