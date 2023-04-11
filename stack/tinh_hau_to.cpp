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
ll cal(ll x, ll y, char c)
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
void solve(string s)
{
    stack<ll> st;
    for (ll i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            st.push((s[i] - '0'));
        }
        else
        {
            ll top1 = st.top();
            st.pop();
            ll top2 = st.top();
            st.pop();
            ll tam = cal(top2, top1, s[i]);
            st.push(tam);
        }
    }
    cout << st.top() << endl;
}
int main()
{
    string s;
    cin >> s;
    solve(s);
}