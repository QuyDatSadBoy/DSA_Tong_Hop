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
ll calc(ll x, ll y, char c)
{
    if (c == '+')
        return x + y;
    if (c == '-')
        return x - y;
    if (c == '*')
        return x * y;
    if (c == '/')
        return (ll)x / y;
    return 0;
}
int main()
{
    // faster();
    ll t;
    cin >> t;
    cin.ignore(1);
    while (t--)
    {
        string s;
        cin >> s;
        stack<ll> st;
        for (ll i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                st.push(1ll * (s[i] - '0'));
            }
            else
            {
                ll top1 = st.top();
                st.pop();
                ll top2 = st.top();
                st.pop();
                ll res = calc(top2, top1, s[i]);
                st.push(res);
            }
        }
        cout << st.top() << endl;
    }
}