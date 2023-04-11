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
    if (c == ('(' || '{' || '['))
    {
        return true;
    }
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
                if (s[i] == '(' && st.top() == ')')
                    st.pop();
                else
                    return false;
                if (s[i] == '{' && st.top() == '}')
                    st.pop();
                else
                    return false;
                if (s[i] == '[' && st.top() == ']')
                    st.pop();
                else
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