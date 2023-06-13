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
ll k;
ll decimal(string s)
{
    ll res = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        res = res * k + (s[i] - '0');
    }
    return res;
}
void convert(ll res)
{
    stack<ll> st;
    while (res)
    {
        ll r = res % k;
        st.push(r);
        res /= k;
    }
    while (st.size())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> k >> s1 >> s2;
        ll res1 = decimal(s1);
        ll res2 = decimal(s2);
        convert(res1 + res2);
    }
}