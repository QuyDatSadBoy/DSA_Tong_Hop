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
ll n;
string s;
vector<string> v;
void back_track(ll pos, string res)
{
    if (pos == n)
        return;
    for (ll j = pos; j < n; j++)
    {
        v.push_back(res + s[j]);
        back_track(j + 1, res + s[j]);
    }
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin.ignore(1);
        cin >> s;
        back_track(0, "");
        sort(all(v));
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
        v.clear();
    }
}