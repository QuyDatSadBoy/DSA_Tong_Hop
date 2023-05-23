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
bool isgood(char c)
{
    if (c == '(' || c == '{' || c == '[')
        return true;
    return false;
}
bool check(char top, char c)
{
    if ((top == '(' && c == ')') || (top == '[' && c == ']') || (top == '{' && c == '}'))
        return true;
    return false;
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
        stack<char> st;
        bool ok = 1;
        for (ll i = 0; i < s.size(); i++)
        {
            if (isgood(s[i]))
                st.push(s[i]);
            else
            {
                if (st.empty())
                {
                    ok = 0;
                    break;
                }
                else
                {
                    if (check(st.top(), s[i]))
                        st.pop();
                    else
                    {
                        ok = 0;
                        break;
                    }
                }
            }
        }
        if (!st.empty())
            ok = 0;
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}