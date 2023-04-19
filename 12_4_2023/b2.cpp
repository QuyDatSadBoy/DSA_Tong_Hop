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
    if (c == '(' || c == '[')
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
        if (s[i] == ' ' || s[i] == '.')
            continue;
        if (st.empty())
        {
            if (s[i] == ']' || s[i] == ')')
            {
                return false;
            }
            if (isgood(s[i]))
                st.push(s[i]);
        }
        else
        {
            if (s[i] == ']')
            {
                if (st.empty())
                    return false;
                if (st.top() != '[')
                    return false;
                st.pop();
            }
            if (s[i] == ')')
            {
                if (st.empty())
                    return false;
                if (st.top() != '(')
                    return false;
                st.pop();
            }
            if (isgood(s[i]))
                st.push(s[i]);
        }
    }
    return st.empty();
}

int main()
{
    faster();
    ll t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        if (check(s))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}