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
    reverse(all(s));
    return tam == s;
}
int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        map<char, int> mp;
        int dem = 1;
        int ok = 1;
        for (int i = 0; i < s.size() / 2; i++)
        {
            mp[s[i]]++;
            if (mp.size() >= 2)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}