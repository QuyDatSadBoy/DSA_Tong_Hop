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
ll value(char c)
{
    if (c == '^')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
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
        cin >> s;
        string res = "";
        stack<char> st;
        for (ll i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
                res += s[i];
            else
            {
                if (s[i] == '(')
                    st.push(s[i]);
                else
                {
                    if (s[i] == ')')
                    {
                        while (!st.empty() && (st.top() != '('))
                        {
                            char top = st.top();
                            st.pop();
                            res += top;
                        }
                        st.pop();
                    }
                    else
                    {
                        while (!st.empty() && value(st.top()) >= value(s[i]))
                        {
                            char top = st.top();
                            st.pop();
                            res += top;
                        }
                        st.push(s[i]);
                    }
                }
            }
        }
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        cout << res << endl;
    }
}