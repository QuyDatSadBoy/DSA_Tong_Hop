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
    return c == '+' || c == '-' || c == '*' || c == '/';
}
bool check(string s)
{
    stack<char> st;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] != ')')
            st.push(s[i]);
        else
        {
            ll ok = 1;
            while (st.top() != '(')
            {
                ll top = st.top();
                st.pop();
                if (isgood(top))
                {
                    ok = 0;
                }
            }
            if (ok)
                return true;
            st.pop();
        }
    }
    return false;
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