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
bool check(string s)
{
    string tam = s;
    ll l = 0, r = s.size() - 1;
    while (l <= r)
    {
        swap(s[l], s[r]);
        l++;
        r--;
    }
    return tam == s;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    cin.ignore(1);
    while (t--)
    {
        ll cnt[26] = {0}, dem = 0;
        string s;
        cin >> s;
        for (auto &x : s)
            cnt[x - 'a']++;
        for (auto x : cnt)
        {
            if (x)
                dem++;
        }
        if (dem == 1)
            cout << -1 << endl;
        else
        {
            cout << s.size() - 1 << endl;
        }
    }
}