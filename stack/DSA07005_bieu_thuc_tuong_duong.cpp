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
void solve(string s)
{
    stack<char> st;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] != ')')
            st.push(s[i]);
        else
        {
            string res = "";
            while (!st.empty() && st.top() != '(')
            {
                res = st.top() + res;
                st.pop();
            }
            st.pop();
            if (!st.empty() && st.top() == '-')
            {
                for (auto x : res)
                {
                    if (x == '-')
                        x = '+';
                    else if (x == '+')
                        x = '-';
                    st.push(x);
                }
            }
            else
            {
                for (auto x : res)
                    st.push(x);
            }
        }
    }
    string res = "";
    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }
    cout << res << endl;
}
int main()
{
    faster();
    ll t;
    cin >> t;
    cin.ignore(1);
    while (t--)
    {
        string s;
        getline(cin, s);
        solve(s);
    }
}