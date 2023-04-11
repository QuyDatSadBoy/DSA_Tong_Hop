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
bool isgood(char c)
{
    if (c == '(' || c == '{' || c == '[')
    {
        return true;
    }
    return false;
}
bool check(string s)
{
    stack<char> st;
    for (ll i = 0; i < s.length(); i++)
    {
        if (st.empty())
        {
            if (!isgood(s[i]))
                return false;
            st.push(s[i]);
        }
        else
        {
            if (isgood(s[i]))
                st.push(s[i]);
            else
            {
                ll ok = 0;
                if (s[i] == ')' && st.top() == '(')
                {
                    ok = 1;
                    st.pop();
                }
                if (s[i] == '}' && st.top() == '{')
                {
                    ok = 1;
                    st.pop();
                }
                if (s[i] == ']' && st.top() == '[')
                {
                    ok = 1;
                    st.pop();
                }
                if (ok == 0)
                    return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    faster();
    string s;
    cin >> s;
    if (check(s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}