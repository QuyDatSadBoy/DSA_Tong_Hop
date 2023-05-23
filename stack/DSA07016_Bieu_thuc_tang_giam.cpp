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
void solve()
{
    string s;
    cin >> s;
    stack<ll> st;
    for (ll i = 0; i <= s.size(); i++)
    {
        st.push(i + 1);
        if (s[i] == 'I' || i == s.size())
        {
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
        }
    }
    cout << endl;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    cin.ignore(1);
    while (t--)
    {
        solve();
    }
}