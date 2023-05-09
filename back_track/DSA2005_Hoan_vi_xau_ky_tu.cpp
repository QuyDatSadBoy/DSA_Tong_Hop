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
bool visited[26] = {0};
string s;
void back_track(ll i, string res)
{
    for (ll j = 0; j < s.size(); j++)
    {
        if (visited[s[j] - 'A'] == 0)
        {
            res += s[j];
            visited[s[j] - 'A'] = 1;
            if (i == s.size() - 1)
                cout << res << " ";
            else
                back_track(i + 1, res);
            res.pop_back();
            visited[s[j] - 'A'] = 0;
        }
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
        cin >> s;
        back_track(0, "");
        cout << endl;
        ms(visited);
    }
}